#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793;
const long double DEL = 1e-10;
const int mod =  1000000007;

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mpq priority_queue<int,vector<int>,greater<int>>
#define deb(a) cerr << #a << ": " << a << endl
#define vvpii vector<vector<pair<int,int>>>
#define ftt cin>>t;for(int tt=1;tt<=t;++tt)
#define Rev(v) reverse(v.begin(),v.end())
#define Sort(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a))
#define forr(i,a,b) for(i=a;i<=b;i++)
#define umii unordered_map<int,int>
#define vpii vector<pair<int,int>>
#define all(a) a.begin() , a.end()
#define vvi vector<vector<int>>
#define pq priority_queue<int>
#define sqr(a) (((a) * (a)))
#define double long double
#define dbg cout<<"\nhi\n"
#define pii pair<int,int>
#define mii map<int,int>
#define vb vector<bool>
#define vi vector<int>
#define int long long
#define nl cout<<"\n"
#define pb push_back
#define sp <<" "<<
#define ss second
#define ff first
inline void read(int &x)
{
      int c = getchar();
      x = 0;
      int neg = 0;
      for(; ((c<48 || c>57) && c != '-'); c = getchar());
      if(c=='-')
      {
            neg = 1;
            c = getchar();
      }
      for(; c>47 && c<58 ; c = getchar())
      {
            x = (x<<1) + (x<<3) + c - 48;
      }
      if(neg)
      {
            x = -x;
      }
}
int fpow(int x, int n)
{
    int res = 1;
    while(n){
          if(n&1){
                res = res * x % mod;
          }
          x = x * x % mod;
          n>>=1;
    }
    return res;
}
int gcd(int a,int b)
{
    if(b == 0)
    {
          return a;
    }
    return gcd(b,a % b);
}
void sieve(int n)
{
      bool prime[1000006];
      memset(prime, true, sizeof(prime));
      int rootn = (int)sqrt(n);
      for (int p = 2; p <= rootn; p++)
      {
            if (prime[p] == true)
            {
                  for (int i = p*p; i <= n; i += p)
                  {
                        prime[i] = false;
                  }
            }
      }
      prime[1] = 0;
}
const int N = 200500;
int cnt, sum, mid, mx, mn, ans, a[N], h[N];
int n, m, d, i, j, k, l, p, q, r, t, w, x, y, z;
bool f, f1, f2;
string s;

//******************************************* CHECK CONSTRAINTS **************************************************
vi seg(4*N);

int query(int i,int a,int b)
{
      if(b<l || a>r)
      {
            return -1e17;
      }
      if(l<=a && b<=r)
      {
            return seg[i];
      }
      return max(query(2*i,a,(a+b)/2),query(2*i+1,(a+b)/2+1,b));
}

void update(int i,int a,int b)
{
      if(a>y || b<y)
      {
            return;
      }
      if(a == b)
      {
            seg[i] = x;
            return;
      }
      
      update(2*i,a,(a+b)/2);
      update(2*i+1,(a+b)/2+1,b);
      seg[i] = max(seg[2*i],seg[2*i+1]);
}

int32_t main()
{     fio;
      cin>>n;
      forr(i,1,n)
      {
            cin>>h[i];
      }
      ans = 0;
      forr(i,1,n)
      {
            cin>>x;
            l = 0;
            r = h[i]-1;
            x = query(1,0,n) + x;
            //cout<<x sp query(1,1,n) sp h[i];nl;
            y = h[i];
            ans = max(ans,x);
            update(1,0,n);
      }
      cout<<ans;
      
     
}
