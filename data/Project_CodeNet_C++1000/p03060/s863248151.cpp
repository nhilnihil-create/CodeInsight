#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int solve(void){
    int N;
    int V[100],C[100];
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> V[i];
    }
    for(int i=1;i<=N;i++){
        cin >> C[i];
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(V[i] - C[i] > 0){
            ans += V[i] - C[i];
        }
    }
    
    return ans;
    
}
int main(void){
    int ans = solve();
    cout << ans << endl;
}
