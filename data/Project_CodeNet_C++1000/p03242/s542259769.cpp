#include <bits/stdc++.h>
using namespace std;
int main()
{
      string n;
      cin >> n;
      string ans;
      for(int i=0; i < 3; i++){
        if(n[i] == '1'){
          ans += '9';
        }else{
          ans += '1';
        }
      }
      cout << ans << endl;
}
