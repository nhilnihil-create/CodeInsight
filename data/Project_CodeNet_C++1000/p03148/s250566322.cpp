#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int used[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> >v;
    for(int i=0; i<n; i++)
    {
        int t,d;
        cin>>t>>d;
        v.push_back({d,t});
    }
    sort(all(v));
    reverse(all(v));
    priority_queue<pair<int,int> >cur,l;
    map<int,int>mp,tot_var;
    ll sz=0,var=0,ans=0,sum=0;
    for(int i=0; i<n; i++)
    {
        int x=v[i].second;
        if(mp[x])
        {
            continue;
        }
        if(sz<k)
        {
            used[i]=1;
            var++;
            sz++;
            tot_var[v[i].second]++;
            sum+=v[i].first;
            cur.push({v[i].first*-1,x});
            mp[x]=1;
        }
        if(sz==k)
            break;
    }
    for(int i=0; i<n; i++)
    {
        if(!used[i])
        {
            tot_var[v[i].second]++;
            sum+=v[i].first;
            cur.push({v[i].first*-1,v[i].second});
            sz++;
            used[i]=1;
        }
        if(sz==k)
            break;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            l.push({v[i].first,v[i].second});
        }
    }
    ans=sum+(var*var);
    while(!l.empty())
    {
        int x=l.top().first;
        int y=l.top().second;
        l.pop();
        int a=cur.top().first*-1;
        int b=cur.top().second;
        cur.pop();
        tot_var[b]--;
        if(tot_var[b]==0)
            var--;
        sum-=a;
        tot_var[y]++;
        if(tot_var[y]==1)
            var++;
        sum+=x;
        ans=max(ans,sum+(var*var));
        cur.push({x*-1,y});
    }
    cout<<ans<<endl;
    return 0;
}
