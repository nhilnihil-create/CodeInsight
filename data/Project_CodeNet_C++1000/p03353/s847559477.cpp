 
/* Great things never come from comfort zones,
"whatever the mind of a man can conceive and believe,it can achieve." */
 
#include <bits/stdc++.h>
#define ll long long
#define scf(n) scanf("%d",&n)
#define lscf(n) scanf("%lld",&n)
#define lpri(n) printf("%lld ",n)
#define pri(n) printf("%d ",(int)n)
#define prin(n) printf("%d\n",(int)n)
#define lprin(n) printf("%lld\n",n)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x)     x.begin(),x.end()
#define tc   int tt; scf(tt); while(tt--)
#define inf INT_MAX
#define ninf INT_MIN
#define gcd __gcd
#define bitcount(n) __builtin_popcount(n)
typedef double dd;
using namespace std;
const ll M =1e9+7;
const int N = 1e5+7;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) 
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

// vector<int> adj[N];
// bool vis[N]={0};

// void dfs(int x)
// {
//     vis[x]=1;
        
//     for(auto it:adj[x])   
//     if(!vis[it])
//     dfs(it);
        
// }

ll me(ll x,ll n)
{
    ll res=1;

    while(n)
    {
        if(n&1)
        res*=x;

        x=x*x;

        n/=2;
    }

    return res;


}




int main()
{

    string s;
    cin>>s;

    int k; scf(k);

    int n=s.size();

    set<string>top;  // k sized set

    rep(i,0,n)
    {

        int m=min(5,n-i);

        rep(j,1,m+1)
        {
            string x=s.substr(i,j);

            int sz=top.size();

            if(sz<k)
            top.insert(x);

            else
            {
                for(auto it:top)
            { 
                if(x<it)
                top.insert(x);

                if(top.size()>k)
                top.erase(*(top.rbegin()));// last element erased i.e k th
            }

            }


        }
    }

    auto it=(--top.end());

    

    cout<< *it;
    


    
}