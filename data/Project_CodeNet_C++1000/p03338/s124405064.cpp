 
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
#define pf push_front
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
const ll mod =1e9+7;
const int N = 1e6+7;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B) 
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

bool m[30]={0},p[30]={0};


int main()
{
    
    int n,mx=0;
    scf(n);
    
    string s;
    cin>>s;
   
    rep(i,0,30)
    m[i]=0,p[i]=0;
    
    rep(i,0,n)
    {
        int ctr=0;
        
        rep(k,0,30)
        m[k]=0,p[k]=0;
        
        rep(j,0,i+1)
        m[s[j]-'a']=1;
        
        rep(k,i+1,n)
        p[s[k]-'a']=1;
        
        rep(l,0,26)
        if(m[l]&&p[l])
        ctr++;
        
        
        
        mx=max(mx,ctr);
        
    }
    
        
    prin(mx);
        
        
         
     

        
}