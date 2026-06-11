#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

pair<string, string> firstHalf[1 << 18];//(赤,青)
pair<string, string> secondHalf[1 << 18];//(逆青,逆赤)
int N;
string S;

signed main() {
    cin >> N >> S;
    for (int mask = 0; mask < (1 << N); ++mask) {
        string red = "";
        string blue = "";
        for (int i = 0; i < N; ++i) {
            if ((mask >> i) & 1) {
                red += S[i];
            } else {
                blue += S[i];
            }
        }
        firstHalf[mask] = make_pair(red, blue);
    }
    for (int mask = 0; mask < (1 << N); ++mask) {
        string red = "";
        string blue = "";
        //逆順
        for (int i = N - 1; i >= 0; --i) {
            if ((mask >> i) & 1) {
                red += S[i + N];
            } else {
                blue += S[i + N];
            }
        }
        secondHalf[mask] = make_pair(blue, red);
    }
    const int size = 1 << N;
    sort(firstHalf, firstHalf + size);
    sort(secondHalf, secondHalf + size);
    int ans = 0;
    rep(i, size) {
        ans += u_b(secondHalf, secondHalf + size, firstHalf[i])
               - l_b(secondHalf, secondHalf + size, firstHalf[i]);
    }
    cout << ans << endl;
    return 0;
}
