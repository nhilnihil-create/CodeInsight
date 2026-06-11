#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, j, k, N, A, B, x, y, count=0, ans=0, sum;
  
  cin >> A >> B;
  
  for(i=A;i<B+1;i++){
    x=i;
    y=0;
    rep(j,5){
      y+=(x%10)*pow(10,4-j);
      x/=10;
    }
    if(i==y)count+=1;
  }
  cout << count;
}


