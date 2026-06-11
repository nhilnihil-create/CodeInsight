#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

bool is_sym(const vector<string>& S, int A){
    const int N = S.size();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int k = j+A, l = i-A;
            if(k>=N) k -= N;
            if(l<0) l += N;
            if(S[i][j]!=S[k][l]) return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    for(auto& s: S) cin >> s;

    ll ans = 0;
    for(int i=0; i<N; i++){
        if(is_sym(S, i)) ans += N;
    }

    cout << ans << endl;
}