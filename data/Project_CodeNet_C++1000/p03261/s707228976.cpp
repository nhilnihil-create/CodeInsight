#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  string w, cpw;
  string ans = "Yes";
  map<string, int> count;
  for(int i=0; i<n; ++i){
    cin >> w;
    if(i==0){
      cpw = w;
      count[w]++;
      continue;
    }
    int size = cpw.size();
    count[w]++;
    if(count[w]>1) ans = "No";
    if(w[0]!=cpw[size-1]) ans ="No";
    cpw = w;
  }

  cout << ans;

  return 0;
}