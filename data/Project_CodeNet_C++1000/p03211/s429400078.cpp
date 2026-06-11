#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  int n = s.size(), ans = 753;
  string num0;
  int num1;
  for(int i=0; i<n-2; ++i){
    num0 = s.substr(i,3);
    num1 = stoi(num0);
    ans = min(ans, abs(753 - num1));
  }
  cout << ans << endl;
  return 0;
}