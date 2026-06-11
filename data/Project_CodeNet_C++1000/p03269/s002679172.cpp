#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
viii edj;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z,k,l;
    cin>>l;
    for(int i=0;i<21;i++){
        if((l>>i)&&1){
            x = (1ll<<i);
            n = i+1;
        }
    }
    for(int i=0;i<n-1;i++){
        edj.pb(mc(i+1,i+2,0));
        edj.pb(mc(i+1,i+2,1ll<<i));
    }

    l-=x;

    for(int i=21;i>=0;i--){
        if((l>>i)&1){
            edj.pb(mc(i+1,n,x));
            x+=(1ll<<i);
        }
    }

    cout<<n<<" "<<edj.size()<<endl;
    for(auto it:edj){
        cout<<it.F.F<<" "<<it.F.S<<" "<<it.S<<endl;
    }
    
    



    return 0;
}