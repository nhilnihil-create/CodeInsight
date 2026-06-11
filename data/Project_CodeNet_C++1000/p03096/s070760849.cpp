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
    int N;
    cin >> N;
    int color[N];
    color[0] = -1;
    ll s[200005];
    ll tots = 1;
    for(int i = 1; i < N + 1; i++){
        int c;
        cin >> c;
        color[i] = c - 1;
    }
    for(int i = 0; i < 200005; i++){
        if(i == color[1]){
            s[i] = 1;
        }else{
            s[i] = 0;
        }

    }
    ll MOD = 1000000007;
    for(int i = 1; i < N + 1; i++){
        ll tmp = 0;
        ll currentCol = color[i];
        tmp = s[currentCol];
        //cout << tmp << endl;
        if(i == N){
            cout << tmp << endl;
            continue;
        }
        if(currentCol != color[i + 1]){
            s[color[i + 1]] = (s[color[i + 1]] + tmp) % MOD;
        }
    }




}
