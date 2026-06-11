#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

ll a,b,c,k;
cin >> a >> b >> c >> k;

if(k % 2 == 0) cout << a - b << endl;
else cout << b - a << endl;



return 0;
}