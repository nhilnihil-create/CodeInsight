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
    
    int l;
    cin >> l;

    int n = 0, m = 0;
    while((1 << n) <= l) {
        n++;
    }
    m += 2 * (n - 1);
    m += __builtin_popcount(l) - 1;
    cout << n << " " << m << endl;
    for(int i = 0; i < n - 1; i++) {
        cout << i + 1 << " " << i + 2 << " " << 0 << endl;
        cout << i + 1 << " " << i + 2 << " " << (1 << i) << endl;
    }
    int curr = 1 << (n - 1); // we already have this as our range, now lets "increase" our range bit by bit
    // if we know a bit is on in l, then that means from the previous node before we should be able to create any values + the curr highest (but we cant include the current one!)
    // so its like, if we know a certain bit is on, we take the previous curr value without the bit on to include that we want every possible value that includes the higher bits and doesnt include this bit and has values lower
    for(int i = n - 2; i >= 0; i--) {
        if(l & (1 << i)) {
            cout << i + 1 << " " << n << " " << curr << endl;
            curr += 1 << i;
        }
    }

    return 0;
}
