#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define modd 998244353
#define PI 3.1415926
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define beg begin()
#define en end()
#define sz(v) (int)((v).size())
#define all(v) (v).begin(),(v).end()
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define endl "\n"
#define forn(i,a,n) for(int i=a;i<int(n);++i)
#define forb(i,a,n) for(int i=int(n)-1;i>=a;--i)
#define cout(ans) cout<< ans << "\n"
#define couts(ans) cout<< ans <<" "
#define coutss(a,b) cout<< a <<" "<< b << "\n"
#define coutsm(a,b,c) cout<< a <<" "<< b <<" "<< c << "\n"
#define maxx *max_element
#define minn *min_element


void speed()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
}

int dp[100001];

void solve()
{      
    int n,k;cin>>n>>k;
    int a[n];
    forn(i,0,n)
    {
        cin>>a[i];
    }
    forn(i,1,k+1)
    {
        forn(j,0,n)
        {
            if(i-a[j]>=0 && !dp[i-a[j]])
            {
                dp[i]=1;
            }
        }
    }
    if(dp[k])
        cout<<"First\n";
    else
        cout<<"Second\n";

}


int main()
{   
    speed();
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
}