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
const int INF = 1e9 + 6;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    int Z, W;
    cin >> N >> Z >> W;
    int A[N]; rep(i, N) cin >> A[i];
    if(N >= 2)cout << max(abs(A[N - 1] - W), abs(A[N - 2] - A[N - 1])) << endl;
    else cout << abs(A[N - 1] - W) << endl;
}
