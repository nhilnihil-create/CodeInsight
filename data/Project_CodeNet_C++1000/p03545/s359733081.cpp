#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int n = s.size();
    
    string ans = "";
    for(int i = 0;i < 1 << (n - 1);i++){
          int x = s[0] - '0';
          string t = s.substr(0,1);
          for(int j = 1;j < n;j++){
                if(i >> (j - 1) & 1){
                      x += (s[j] - '0');
                      t += "+" + s.substr(j,1);
                }else{
                      x -= (s[j] - '0');
                      t += "-" + s.substr(j,1);
                }
          }
          if(x == 7)ans = t + "=7";
    }
    cout << ans << endl;
}
