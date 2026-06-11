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

int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<ll> w(N), b(N);
    b[0] = (S[0]=='#') ? 1 : 0;
    w[N-1] = (S[N-1]=='.') ? 1 : 0;
    for(int i=1; i<N; i++){
        b[i] = b[i-1];
        if(S[i]=='#') b[i]++; 
    }
    for(int i=N-2; i>=0; i--){
        w[i] = w[i+1];
        if(S[i]=='.') w[i]++;
    }

    ll ans = min(w[0], b[N-1]);
    for(int i=0; i<N-1; i++) ans = min(ans, b[i]+w[i+1]);

    cout << ans << endl;
}
