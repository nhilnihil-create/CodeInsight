#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

bool solve(string& S, string& T, int dist, int M, char to, char rev)
{
    int d = dist;
    for(int i=0; i<S.size(); i++){
        if(S[i] == to){
            d--;
            if(d <= 0) return false;
        }
        if(T[i] == rev) d = min(d+1, M);
    }
    return true;
}

int main()
{
    int H, W, N, sr, sc;
    cin >> H >> W >> N >> sr >> sc;
    string S, T;
    cin >> S >> T;

    bool ans = true;
    ans &= solve(S, T, sr, H, 'U', 'D');
    ans &= solve(S, T, H-sr+1, H, 'D', 'U');
    ans &= solve(S, T, sc, W, 'L', 'R');
    ans &= solve(S, T, W-sc+1, W, 'R', 'L');

    if(ans) cout << "YES\n";
    else cout << "NO\n";
}