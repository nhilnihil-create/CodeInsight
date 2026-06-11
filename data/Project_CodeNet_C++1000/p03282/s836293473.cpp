#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    string S;
    ll K;
    cin >> S >> K;
    int ans = 1;
    rep(i, S.size()){
        if(K <= i + 1){
            cout << S[i] << endl;
            return 0;
        }
        if(S[i] != '1'){
            cout << S[i] << endl;
            return 0;
        }
    }
}