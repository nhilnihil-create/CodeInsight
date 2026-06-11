#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int H, W, N, sr, sc;
string S, T;

bool action(int i, int j, char a){
    if(a == 'L') return j <= (W + 1) / 2;
    else if(a == 'R') return W + 1 - j <= (W + 1) / 2;
    else if(a == 'U') return i <= (H + 1) / 2;
    else if(a == 'D') return H + 1 - i <= (H + 1) / 2;
}

signed main(){
    cin >> H >> W >> N >> sr >> sc;
    cin >> S >> T;
    int l = 1, r = W;
    for(int i = N - 1; i >= 0; i--){
        if(T[i] == 'L') r = min(r + 1, W);
        else if(T[i] == 'R') l = max(l - 1, 1);
        if(S[i] == 'L') l++;
        else if(S[i] == 'R') r--;
        if(l > r){
            PRINT("NO");
            return 0;
        }
    }
    if(sc < l || r < sc){
        PRINT("NO");
        return 0;
    }
    l = 1, r = H;
    for(int i = N - 1; i >= 0; i--){
        if(T[i] == 'U') r = min(r + 1, H);
        else if(T[i] == 'D') l = max(l - 1, 1);
        if(S[i] == 'U') l++;
        else if(S[i] == 'D') r--;
        if(l > r){
            PRINT("NO");
            return 0;
        }
    }
    if(sr < l || r < sr){
        PRINT("NO");
        return 0;
    }
    PRINT("YES");
    return 0;
}