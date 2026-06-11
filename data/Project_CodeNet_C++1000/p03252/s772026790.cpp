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
    string S, T;
    cin >> S >> T;
    bool frag = true;
    int n = S.size();
    int i = 0;
    vvi ansS(26, vi(n));
    vvi ansT(26, vi(n));
    for (char x : alphabet) {
        rep(j, n) {
            if (S[j] == x)ansS[i][j] = 1;
            if (T[j] == x)ansT[i][j] = 1;
        }
        i++;
    }
    rep(j, 26) {
        rep(k,ansT.size()) {
            if (ansS[j] == ansT[k]) {
                ansT.erase(ansT.begin()+k);
                break;
            }
        }
    }
    if (!ansT.empty())frag = false;
    if (frag) cout << "Yes" << endl;
    else cout << "No" << endl;
}