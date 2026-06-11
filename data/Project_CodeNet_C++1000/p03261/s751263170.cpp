#include <iostream>
#include <vector>
using namespace std;

int main(void){
      int n;
      cin >> n;
      vector<string> s(n);
      for(int i = 0;i < n;i++){
            cin >> s[i];
      }
      bool f = true;
      for(int i = 1;i < n;i++){
            if(s[i][0] != s[i - 1][s[i - 1].size() - 1]){
                  f = false;
            }
            for(int j = 0;j < i;j++){
                  if(s[j] == s[i]){
                        f = false;
                  }
            }
      }
      
      cout << ((f) ? "Yes" : "No") << endl;
}
