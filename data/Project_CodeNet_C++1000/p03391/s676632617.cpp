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

int main()
{
    int N;
    cin >> N;
    ll A, B;
    ll m = 1e18, s = 0;
    for(int i=0; i<N; i++){
        cin >> A >> B;
        s += A;
        if(A > B) m = min(m, B);
    }

    cout << ((m > 1e17) ? 0 : s - m) << endl;
}