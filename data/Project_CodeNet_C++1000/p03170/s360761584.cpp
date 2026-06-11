#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LI list<int>
#define vct vector
#define D(a) (double)(a)
#define vi vct<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vvi vct<vi>
#define vll vct<ll>
#define vvll vct<vll>
#define vpii vct<pii>
#define vpll vct<pll>
#define vb vct<bool>
#define vs vector<string>
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define ff first
#define ss second
#define bg begin()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define ft cout<<"for test"<<endl;
#define read(v,a,n) for(int i=a; i<n; i++)cin>>v[i];
#define print(v) for(auto it:v)cout<<it<<' '; cout<<endl;
#define PI acos(-1.0)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test,cs=1;cin>>test;while(test--)
#define rt return true
#define rf return false
///................function.....................///
#define siz(s) (int)(s.size())
#define mod 1000000007
#define dbg(a) cout << #a << " = " << a << " ";
int main()
{
    ///freopen("input15.txt","r",stdin);
    ///freopen("output15.txt","w",stdout);
    int n,k,i,j;
    cin>>n>>k;
    vb dp(k+1);
    vi v(n);
    read(v,0,n);
    for(i=1; i<=k; i++)
    {
        for(j=0; j<n; j++)
            if((i-v[j]>=0)&&(!dp[i-v[j]]))
                dp[i]=1;
    }
    if(dp[k])
        cout<<"First"<<endl;
    else cout<<"Second"<<endl;

}
