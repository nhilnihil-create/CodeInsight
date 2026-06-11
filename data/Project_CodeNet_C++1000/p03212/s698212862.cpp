#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
int n, ans=0;
void calc(int x, int a, int b, int c){
    if(x>n)return;
    if(a&&b&&c)ans++;
    calc(x*10+3, 1ll, b, c);
    calc(x*10+5, a, 1ll, c);
    calc(x*10+7, a, b, 1ll);
}
void solve(){
    cin>>n;
    calc(0ll, 0ll, 0ll, 0ll); 
    cout<<ans;  
}
signed main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)solve();
}