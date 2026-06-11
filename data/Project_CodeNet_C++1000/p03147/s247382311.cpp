#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main() {
    int N;
    cin >> N;
    vi h(N);
    rep(i, N)cin >> h[i];
    int ans = 0;
    int k = 0;
    while(k<N) {
        int min = 101;
        bool frag = false;
        if (h[k] != 0) {
            int index = k;
            frag = true;
        }int j = k;
        while (j < N && h[j] != 0) {
            if (h[j] < min)min = h[j];
            j++;
        }
        if (k != j) for (int i = k; i <= j - 1; i++)h[i] -= min;
        else {
            min = h[k];
            h[k] = 0;
        }
        ans += min;
        if(!frag) k++;
    }
    cout << ans << endl;
}