#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=0, b=101, x=0;
  int c=0;
  cin >> a >> b;
  if(a<1||100<b) cout << "入力エラー(制約 : 1≦a, b≦100)" << endl;
  else{
    c = (a+b)%2;
    x = (a+b)/2;
    if(0<c) x = x+1;
    cout << x << endl;
  }
}
