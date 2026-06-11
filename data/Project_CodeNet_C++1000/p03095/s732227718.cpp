#include <iostream>
#include<vector>

using namespace std;
int main(void){
      int n;
      cin >> n;
      string s;
      cin >> s;
      vector<int> v(26,1);
      
      for(int i = 0;i < s.size();i++){
            v[s[i] - 'a']++;
      }
      long ans = 1;
      for(int i = 0;i < v.size();i++){
            ans = ans * v[i] % 1000000007;
      }
      ans = (ans - 1 + 1000000007) % 1000000007;
      cout << ans << endl;
}
   
