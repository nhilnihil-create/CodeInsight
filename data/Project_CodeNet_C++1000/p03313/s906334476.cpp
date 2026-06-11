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
    int M = 1<<N;
    vector<int> A(M), u(M), v(M);
    for(int i=0; i<M; i++){
        cin >> A[i];
        u[i] = i;
    }

    auto comp = [&](const int a, const int b){
        if(A[a]==A[b]) return a < b;
        return A[a] < A[b];
    };
    set<int, decltype(comp)> st(comp);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if((j>>i)&1){
                st.clear();
                int k = j ^ (1<<i);
                if(v[j] != -1) st.insert(v[j]);
                if(v[k] != -1) st.insert(v[k]);
                st.insert(u[j]);
                st.insert(u[k]);

                auto itr = st.end();
                u[j] = *(itr = prev(itr));
                v[j] = *(itr = prev(itr));
            }
        }
    }

    int ans = 0;
    for(int i=1; i<M; i++){
        ans = max(ans, A[u[i]] + A[v[i]]);
        cout << ans << "\n";
    }
}