#include <iostream>
#include <utility>
#include <queue>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
    vector<ll> vec(87,0);
    vec[0] = 2;
    vec[1] = 1;
    int n;
    cin >> n;
    reps(i,2,87){
        vec[i] = vec[i-1] + vec[i-2];
    }

    cout << vec[n] << endl;
    return 0;
}