#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N,M;
  cin >> N >> M;
  
  int a, b;
  int left=0;
  int right= 1000000;
  rep(i,N){
    cin >> a >> b;
    if( left <=  a)left = a;
    if( right >= b)right = b;
  }
  
  if(right < left)cout << 0 << endl;
  
  else cout << right - left +1 << endl;
  
  
}