#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll binpow(ll x,ll y)/* (x^y)%p in O(log y) */{ll res=1;while (y > 0){if(y&1)res=(res*x);y = y>>1;x=(x*x);}return res;}
ll binpowmod(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ull res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpowmod(n,p-2,p);}
ll gcd(ll x,ll y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
bool comp_pairs_by_s(pair<ll,ll> &x ,pair<ll,ll> &y)
{
    return x.second<y.second;
}
bool isPowerOfTwo (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}

class cmp      //comparator for priority_queue 
{               //declaration: priority_queue<int,vector<int>,cmp>
public:         
    bool operator()(pair<int,int> A,pair<int,int> B)
    {
        if(abs(A.first-A.second)==abs(B.first-B.second))
            return A.first>B.first;
        return abs(A.first-A.second)<abs(B.first-B.second);
    }
};
// int prime[10000007]={0};
// void sieve(void)
// {
//  int i,j;
//  for(i=0;i<10000007;i++)
//         prime[i]=1;
//  prime[0]=0,prime[1]=0;
//  for(i=2;i<=sqrt(10000007);i++){
//      if(prime[i]==i){
//          for(j=i*i;j<10000007;j+=i){
//             if(!prime[j])
//                 prime[j]=0;
//          }
//      }
//  }
    
// }
void swap(ll &x,ll &y){
    int temp=x;
    x=y;
    y=temp;
}
  
unsigned int onesComplement(unsigned int n) 
{ 
   // Find number of bits in the given integer 
   int number_of_bits = floor(log2(n))+1; 
  
   // XOR the given integer with poe(2,  
   // number_of_bits-1 and print the result  
   return ((1 << number_of_bits) - 1) ^ n; 
}
void solve()
{   
    int n,cc;
    cin>>n>>cc;
    vector<vector<int>> c(n,vector<int>(n));
    vector<vector<int>> d(cc+1,vector<int>(cc+1));
    vector<vector<int>> cnt(3,vector<int>(cc+1,0));
    for(int i=1;i<=cc;++i)
        for(int j=1;j<=cc;++j)
            cin>>d[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>c[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cnt[(i+j+2)%3][c[i][j]]++;
    int wness=INT_MAX;
    debug(cnt);
    for(int c1=1;c1<=cc;++c1)
        for(int c2=1;c2<=cc;++c2)
            for(int c3=1;c3<=cc;++c3){
                if(c1==c2 || c2==c3 || c3==c1) continue;
                vector<int> color(3);
                color[0]=c1;
                color[1]=c2;
                color[2]=c3;
                int cnt1=0;
                for(int i=0;i<3;++i){
                    for(int j=1;j<=cc;++j){
                        cnt1+=cnt[i][j]*d[j][color[i]];
                    }
                }
                wness=min(wness,cnt1);
            }
    cout<<wness;


}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    solve();
}   
