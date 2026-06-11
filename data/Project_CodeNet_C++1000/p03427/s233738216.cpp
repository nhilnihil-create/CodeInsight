#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    int ans = 0;
    int ans2 = 0;
    while(n > 0) {
        int del = 9;
        if(n / 10 == 0) {
            del = n - 1;
        }
        ans2 += n % 10;
        ans += del;
        n /= 10;
    }
    cout << max(ans, ans2) << endl;
    return 0;
}