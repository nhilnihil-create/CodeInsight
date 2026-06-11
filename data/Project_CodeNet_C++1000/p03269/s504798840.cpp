#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int i, j, k;
    int L, N = 0;
    cin >> L;
    while(1<<N <= L) N++;
    vector<vector<int>> ans;
 
    // 2進数の辺を作る
    for(i=1; i<N; i++){
        ans.push_back({i, i+1, 1<<(i-1)});
        ans.push_back({i, i+1, 0});
    }
 
    // 今できている経路の最大長。これをL-1にするまで経路を足す。
    int now = (1<<(N-1)) - 1;
 
    for(i=N-1; i>=1; i--){
        if(now == L-1) break;
        
        // 頂点iからのショートカット追加で増える経路数
        int gain = 1<<(i-1);
 
        if(now + gain <= L-1){
            ans.push_back({i, N, now+1});
            now += gain;
        }
    }
 
    int M = ans.size();
    cout << N << " " << M << endl;
    for(auto v : ans){
        cout << v[0] << " " << v[1] <<  " " << v[2] << endl;
    }
    return 0;
}