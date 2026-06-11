#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int F[n][10], P[n][11];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> F[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 11; ++j){
            cin >> P[i][j];
        }
    }
    int ans = -1e9;
    for(int i = 0; i < 1<<10; ++i){
        if(i == 0) continue;
        int sum = 0;
        for(int j = 0; j < n; ++j){
            int cnt = 0;
            for(int k = 0; k < 10; ++k){
                if((i>>k)&1 && F[j][k]) cnt++;
            }
            sum += P[j][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}