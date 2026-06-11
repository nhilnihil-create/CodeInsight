#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;


int main() { 
    ll N, M, C, x, sum, n=0;
    cin >> N >> M >> C ;
    vector<ll> B;
    for(int i=0; i<M; i++){
        cin >> x;
        B.emplace_back(x);
    }

    for(int j=0; j<N; j++){
        sum=C;
        for(int i=0; i<M; i++){
            cin >> x;
            sum += x*B[i];
        }
        if(sum > 0) n++;
    }
    cout << n << endl;
}