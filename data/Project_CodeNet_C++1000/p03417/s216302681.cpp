#include<bits/stdc++.h>
using namespace std;

/*
周囲にあるカードの枚数+1回返される
n,m>2のとき周囲の枚数は 3,5,8のどれか
n==1||m==1なら 0,1,2
裏になるのは周囲に0,2,8枚の時だけ
*/
int main(){
  int64_t n,m;
  cin >> n >> m;
  cout << ((n!=1&&m!=1)?(n-2)*(m-2):(n!=1)?(n-2):(m!=1)?(m-2):1) << endl;
  return 0;
}