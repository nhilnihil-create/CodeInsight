#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
   int n;
   cin >> n;
   int fans = 1e9;
   for (int i = 1; i < n;i++){
      string s,t;
      s = to_string(i); t = to_string(n-i);
      int ans = 0;
      for (int j = 0;j < s.size();j++){
         ans += stoi(s.substr(j,1));
      }
      for (int j = 0;j < t.size();j++){
         ans += stoi(t.substr(j,1));
      }
      fans = min(ans,fans); 
   }
   cout << fans << endl;
   
   
   return 0;
}

