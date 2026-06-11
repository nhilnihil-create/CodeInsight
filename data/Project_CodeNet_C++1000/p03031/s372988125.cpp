#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> k(m),p(m);
    vector<int> s[m];
    for(int i=0; i<m; i++){
        cin >> k[i];
        for(int j=0; j<k[i]; j++){
            int x;
            cin >> x;
            s[i].push_back(x-1);
            }
        }
    for(int i=0; i<m; i++) cin >> p[i];
  
  int ans=0;
  for (int bits=0; bits < (1<<n); bits++) {
    bool flag = true;
    for(int i=0; i<m; i++){
      int sum=0;
      for(int j=0; j<k[i]; j++){
        sum += ((bits>>s[i][j]) & 1);
      }
      if(sum%2 != p[i]) flag = false;      
     }
    if (flag) ans++;
   } 
  cout << ans << endl;
}
 
