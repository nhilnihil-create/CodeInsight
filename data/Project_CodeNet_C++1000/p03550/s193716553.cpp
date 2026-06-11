#include<bits/stdc++.h>
#include<bitset>
#include<random>
#include<time.h>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

int main()
{
  int n, w, z;
  cin>>n>>w>>z;
  ll arr[n];
  if(n == 1)
  {
    cin>>arr[0];
    cout<<(abs(z - arr[0]))<<endl;
    return 0;
  }
  rep(i, 0, n)
    cin>>arr[i];
  ll ans = max(abs(z-arr[n-1]), abs(arr[n-1] - arr[n-2]));
  cout<<ans<<endl;
}
