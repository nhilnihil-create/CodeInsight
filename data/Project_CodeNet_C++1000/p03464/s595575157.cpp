#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll K;
    cin >> K;
    ll A[K];
    for(ll i = 0; i < K; i++){
        cin >> A[i];
    }
    ll m = 2;
    ll M = 2;
    for(ll i = K - 1; i >= 0; i--){
        m = ceil((double)m / (double)A[i]) * A[i];
        M = floor((double)M / (double)A[i]) * A[i] +  (A[i] - 1);
        if(ceil((double)M / (double)A[i]) == floor((double)m / (double)A[i])){
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << m <<" " << M << endl;
}
