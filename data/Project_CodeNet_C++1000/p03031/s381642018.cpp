#include <iostream>
#include<vector>
using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for(int i = 0;i < m;i++){
          int k;
          cin >> k;
          a[i].resize(k);
          for(int j = 0;j < k;j++){
                cin >> a[i][j];
                a[i][j]--;
          }
    }
    vector<int> p(m);
    for(int i = 0;i < m;i++){
          cin >> p[i];
    }
    int ans = 0;
    for(int i = 0;i < 1 << n;i++){
          bool ok = true;
          for(int j = 0;j < m;j++){
                int c = 0;
                for(int id:a[j]){
                      if(i >> id & 1){
                            c++;
                      }
                }
                if(c % 2 != p[j])ok = false;
          }
          if(ok)ans++;
    }
    
    cout << ans << endl;
}
