#include <bits/stdc++.h>

using namespace std;

int main(){
 int a;
 int d[5]={0};
  
    for(int i=0;i<6;i++){
   cin >>a;
    d[a]++;
  }
  
  if(d[1]<=2&&d[2]<=2&&d[3]<=2&&d[4]<=2) cout << "YES" << endl;
  else cout << "NO" << endl;
}