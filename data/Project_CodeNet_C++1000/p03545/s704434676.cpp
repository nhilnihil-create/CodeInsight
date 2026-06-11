#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;

  int a, b, c, d;
  a = s[0]-'0'; b = s[1]-'0'; c = s[2]-'0'; d = s[3]-'0';
  
  if(a-b-c-d == 7) printf("%d-%d-%d-%d=7\n",a,b,c,d);
  else if(a-b-c+d == 7) printf("%d-%d-%d+%d=7\n",a,b,c,d);
  else if(a-b+c+d == 7) printf("%d-%d+%d+%d=7\n",a,b,c,d);
  else if(a-b+c-d == 7) printf("%d-%d+%d-%d=7\n",a,b,c,d);
  else if(a+b+c-d == 7) printf("%d+%d+%d-%d=7\n",a,b,c,d);
  else if(a+b-c+d == 7) printf("%d+%d-%d+%d=7\n",a,b,c,d);
  else if(a+b-c-d == 7) printf("%d+%d-%d-%d=7\n",a,b,c,d);
  else if(a+b+c+d == 7) printf("%d+%d+%d+%d=7\n",a,b,c,d);


}