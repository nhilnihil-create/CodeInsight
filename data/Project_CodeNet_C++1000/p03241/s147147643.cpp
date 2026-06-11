#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//約数列挙
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
    ll n,m;
    cin >> n >> m;
    vector<int> y = comdiv(m);
    int ans;
    for(auto p:y){
        if(m-p*(n-1) > 0) ans = p;
    }
    cout << ans << endl;
}