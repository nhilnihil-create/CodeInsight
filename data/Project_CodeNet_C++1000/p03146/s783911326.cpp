#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int s;
  cin >> s;
  int cnt=1;
  if(s==2 || s==1 ){
    cout << 4;
    return 0;
  }
  while(1){
    if(s==4) break;
    cnt++;
    if(s%2==0) s /= 2;
    else s = 3*s+1;
  }

  cout << cnt+3 << endl;
  return 0;
}
