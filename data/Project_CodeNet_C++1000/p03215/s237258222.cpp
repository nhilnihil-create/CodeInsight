#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    node(ll _val = 0,node *_pre = NULL,node *_nx = NULL):value(_val),pre(_pre),nx(_nx){}
    ll value;
    node *pre,*nx;
};

struct link{
    node *head = new node();
    node *tail = head;
    void add(ll val)
    {
        node *p = new node(val,tail);
        tail->nx = p;
        tail = p;
    }
    node *del(node *p)
    {
        node * tmp = p->pre;
        if (p == tail)
        {
            tail = p->pre;
            tail->nx = NULL;
            delete p;
        }
        else
        {
            node *pre = p->pre,*nx = p->nx;
            pre->nx = nx;
            nx->pre = pre;
            delete p;
        }
        return tmp;
    }
    void write()
    {
        node *j = head;
        while (j->nx != NULL)
        {
            j = j->nx;
            cout<<j->value<<' ';
        }
        cout<<'\n';
    }
}L;

const int N = 1e3+10;
ll n,k,a[N],sum[N],tot,num[50];
int main()
{
    int st;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    sum[i]=sum[i-1]+a[i];
    ll maxn = 0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            L.add(sum[j]-sum[i-1]);
            maxn = max(maxn,sum[j]-sum[i-1]);
            num[(int)(log(sum[j]-sum[i-1]) / log(2))]++;
            tot++;
        }
    st = log(maxn) / log(2);
    int cnt = 0,i;
    for (i = st;i>=0;i--)
    {
        cnt += num[i];
        if (cnt > k) break;
    }
    node* j = L.head;
    ll ans = (1LL<<40) - 1;
    while (j->nx != NULL)
    {
        j = j->nx;
        if ((j->value) < (1LL<<i))
        {
            j = L.del(j);
        }
    }
    for (i--;i>=0 && cnt > k;i--)
    {
        j = L.head;
        int tmp = 0;
        while (j->nx != NULL)
        {
            j = j->nx;
            if (((j->value) & (1LL<<i)) == 0) tmp++;
        }
        j = L.head;
        if (cnt - tmp >= k)
        {
            while (j->nx != NULL)
            {
                j = j->nx;
                if (((j->value) & (1LL<<i)) == 0) j = L.del(j);
            }
            cnt -= tmp;
        }
        else
        {
            int cnt1 = 0;
            while (j->nx != NULL)
            {
                j = j->nx;
                if (((j->value) & (1LL<<i)) == 1)
                {
                    cnt1++;
                    ans &= j->value;
                    j = L.del(j);
                }
            }
            cnt -= cnt1;
            k -= cnt1;
        }
        // L.write();
    }
    j = L.head;
    while (j->nx != NULL)
    {
        j = j->nx;
        ans &= j->value;
    }
    cout<<ans;
}
