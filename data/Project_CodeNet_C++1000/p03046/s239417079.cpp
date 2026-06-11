#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int M, K;
    cin >> M >> K;
    int x = 0;
    int maxX = pow(2, M) - 1;
    if(M < 2){
        if(K == 0){
            rep(i, pow(2, M+1)){
            cout << i/2 << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }
    if(maxX < K){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    for(int i = 0;i <= maxX; i++){
        if(i == K) continue;
        ans.push_back(i);
    }
    ans.push_back(K);
    for(int i = maxX;i >= 0;i--){
        if(i == K) continue;
        ans.push_back(i);
    }
    ans.push_back(K);

    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;


    return 0;
}
