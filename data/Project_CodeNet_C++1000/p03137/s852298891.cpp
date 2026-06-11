#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int Mx=1e6+11;
const double PI = acos(-1);
#define MOD 1000000007

#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define tt int t; cin>>t; while(t--)
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

void solve()
{
  int n,m;
  cin>>n>>m;
  int a[m];
  vi v;
  for(int i=0;i<m;i++)
  {
    cin>>a[i];
  }
  sort(a,a+m);
  for(int i=1;i<m;i++)
  {
    v.pb(a[i]-a[i-1]);
  }
  sort(be(v));
  ll sum=0;
  for(int i=0;i<(m-n);i++)
  {
    sum+=v[i];
  }
  cout<<sum<<nl;
}

int main()
{
    fio;
    solve();
    return 0;
}
