#include <bits/stdc++.h>
using namespace std;
 
int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}
 
int main(){
    int M, K;
    cin >> M >> K;
    if(M == 1){
        if(K == 0){
            cout << "0 0 1 1" << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }
    int MX = 1<<M;
    if(K >= MX){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    for(int i=0; i<MX; i++) if(i != K) ans.push_back(i);
    ans.push_back(K);
    for(int i=MX-1; i>=0; i--) if(i != K) ans.push_back(i);
    ans.push_back(K);
    for(int i=0; i<2*MX; i++) cout << ans[i] << " \n"[i==2*MX-1];
    return 0;
}