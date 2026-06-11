#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N, A_0, B_0, A_G, B_G; cin >> N >> A_0 >> B_0 >> A_G >> B_G;
    string S; cin >> S;
    S = '#' + S + '#';
    bool ok = true;
    if(A_G > B_G) {// A_0 -> B_0 -> B_G -> A_G
        //b_0 -> a_g の間でおいぬき
        bool canPassing = false;
        for(int i = B_0 - 1; i < B_G; ++i) {
            if(S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
                canPassing = true;
                break;
            }
        }
        if(!canPassing) ok = false;
    }

    for(int i = A_0; i < A_G; ++i) {
        if(S[i + 1] == '#' && S[i] == '#') {
            ok = false;
            break;
        }
    }
    for(int i = B_0; i < B_G; ++i) {
        if(S[i + 1] == '#' && S[i] == '#') {
            ok = false;
            break;
        }
    }
    cout << ((ok) ? "Yes" : "No") << endl;
}
