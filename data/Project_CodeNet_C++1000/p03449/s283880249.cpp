#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(2,vector<int>(n));
    for(int i = 0;i < 2;i++){
          for(int j = 0;j < n;j++){
                cin >> a[i][j];
          }
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
          int t = 0;
          for(int j = 0;j <= i;j++){
                t += a[0][j];
          }
          for(int k = i;k < n;k++){
                t += a[1][k];
          }
          ans = max(ans,t);
    }
    cout << ans << endl;
}
