#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

int gcd(int a, int b ){ 
  if( b == 0 ){ return a;}
  else{ return gcd(b,a%b);}
}

signed main(void){ 
  
  int t; cin >> t;
  
  while(t--){
    int a,b,c,d; cin >> a >> b >> c >> d;
    if( a < b || d < b ){ //明らかにダメ ジリ貧になるため
      cout << "No" << endl; continue;
    }
    
    if( c >= b ){ cout << "Yes" << endl; continue;//必ず回せるため問題なし
                }
    // 以下、 a >= b かつ d >= b かつ b > c の場合を考える
    // a+d*x-b*yがcよりでかくbより小さい値をとるとまずい(x,yは0以上の整数)
    // d*x-b*yが取れるもっとも絶対値の細かい値はgcd(b,d)と思われる
    //　c < a+k*g < bなる整数kがとれるか調べれば良い
    
    int g = gcd(b,d);
    int k = abs(b-a)/g;
    k *= -1;
    k--;
    int res = a+k*g;
    if( c < res && res < b ){ cout << "No" << endl; continue;}
    else{ cout << "Yes" << endl; continue;}
    
  }
  
  return 0;
}