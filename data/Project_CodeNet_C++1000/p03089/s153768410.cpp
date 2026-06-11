#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;


int main(){
    ll N;
    cin >> N;
    vector<ll> B(N);
    for(int i=0;i<N;i++){
        cin >> B[i];
        if(B[i]>i+1){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<bool> alreadyUsed(N,false);
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=0;--j){
            if(alreadyUsed[j]){
                continue;
            }
            if(B[j] <= i+1){
                int num=0;
                for(int k=0;k<j;k++){
                    if(alreadyUsed[k]){
                        num++;
                    }
                }
                if(num>=B[j]-1){
                    cout << B[j] << endl;
                alreadyUsed[j] = true;
                break;
                }
                
            }
        }
    }
    
    // Failed to predict input format
    return 0;
}
