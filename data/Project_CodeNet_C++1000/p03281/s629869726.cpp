#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> a(201,0);
    
    int ans = 0;
    for(int i = 105;i <= n;i += 2){
          for(int j = 1; j <= n;j+= 2){
                if(i % j == 0)a[i]++;
          }
    }
    for(int i = 0;i <= n;i++){
          if(a[i] == 8) ans++;
    }
    cout << ans << endl;
}
