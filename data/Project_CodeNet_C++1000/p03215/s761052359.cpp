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
            tot++;
        }
    st = log(maxn) / log(2);
    node *j;
    // L.write();
    for (int i = st;i>=0;i--)    
    {
        j = L.head;
        int tmp = 0;
        while (j->nx != NULL)
        {
            j = j->nx;
            if (((j->value) & (1LL<<i)) == (1LL<<i)) tmp++;
        }
        if (tmp >= k)
        {
            j = L.head;
            while (j->nx != NULL)
            {
                j = j->nx;
                if (((j->value) & (1LL<<i)) == 0) j = L.del(j);
            }   
            tot = tmp;
        }
        // L.write();
    }
    ll ans = (1LL<<40) - 1;
    j = L.head;
    while (j->nx)
    {
        j = j->nx;
        ans &= j->value;
    }
    cout<<ans;
}