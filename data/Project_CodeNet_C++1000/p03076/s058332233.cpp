#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> V(5);
    int ans = 1000;
    for(int i = 0; i < 5; ++i) cin >> V[i];
    for(int i = 0; i < 5; ++i){
        int buf = 0;
        for(int j = 0; j < 5; ++j){
            if(j != i){
                if(V[j] % 10 > 0) buf += 10*(V[j]/10+1);
                else buf += 10*(V[j]/10);
            }
            else buf += V[j];
        }
        ans = min(ans, buf);
    }
    cout << ans << endl;
    return 0;
}