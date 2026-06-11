#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

vector<int> comdiv(int x){
    vector<int> res;
    stack<int> big;
    for(int i = 1; i*i <= x; i++){
        if(x%i == 0){
            res.push_back(i);
            big.push(x/i);
        } 
    }
    while(!big.empty()){
        res.push_back(big.top());
        big.pop();
    }
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> can = comdiv(m);
    int ans = 0;
    for(int i = 0; i < can.size(); i++){
        if(can[i] <= m/n) ans = can[i];
    }
    cout << ans << endl;
}