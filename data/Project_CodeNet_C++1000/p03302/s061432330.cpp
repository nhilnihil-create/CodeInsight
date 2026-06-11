#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define repi(i,a,b) for (int i=a;i<(b);i++)
using namespace std;
typedef long long ll;

int main(){
 //erさんの提出結果をうつしました
  cin.tie(0); //cin高速化
  ios::sync_with_stdio(false); //cin高速化
  
  int a,b;
  cin >> a >> b;
  
  if(a+b==15){
    cout<<'+'<<endl;
  }else if(a*b==15){
    cout<<"*"<<endl;
  }else{
    cout<<'x'<<endl;
  }
  
  return 0;
}
    