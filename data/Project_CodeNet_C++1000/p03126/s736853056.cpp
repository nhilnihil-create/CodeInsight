#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, m;
  cin >> n >> m;
  int k, a;
  int num[m+1] ={};
  for(int i=0; i<n; ++i){
    cin >> k;
    for(int j=0; j<k; ++j){
      cin >> a;
      num[a]++;
    }
  }

  int cnt =0;
  for(int i=0; i<=m; ++i){
    if(num[i]==n) cnt++;
  }
  cout << cnt;
  return 0;
}