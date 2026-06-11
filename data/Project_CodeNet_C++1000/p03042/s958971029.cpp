#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c;
  string s,t;
  cin >>a;
  b=a/100;
  c=a%100;
  if(0<b&&b<13&&0<c&&c<13){
    s="AMBIGUOUS";
  }else if(0<b&&b<13){
    s="MMYY";
  }else if(0<c&&c<13){
    s="YYMM";
  }else{
    s="NA";
  }
  cout <<s;
}