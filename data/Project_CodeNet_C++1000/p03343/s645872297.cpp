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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    for(auto& x: A) cin >> x;

    ll ans = 1e10;
    for(int i=0; i<N; i++){
        vector<ll> vec;
        priority_queue<ll, vector<ll>, greater<ll> > tmp;
        for(int j=0; j<N; j++){
            if(A[j] >= A[i]) tmp.push(A[j]);
            if(A[j] < A[i] || j == N-1){
                while(!tmp.empty()){
                    if(tmp.size() >= K) vec.push_back(tmp.top());
                    // cout << tmp.top() << " ";
                    tmp.pop();
                }
            }
        }

        if(vec.size() < Q) continue;
        sort(vec.begin(), vec.end());
        ans = min(ans, vec[Q-1] - A[i]);
    }

    cout << ans << endl;
}