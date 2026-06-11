#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};


int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vi A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int ans = X;
    for (int x : A) {
        int i = 0;
        while (1 + i * x <= D) {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
}