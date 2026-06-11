#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int r,d,x;
  cin >> r >> d >> x;

  rep(i,10){
    x = r*x-d;
    cout << x << endl;
  }
}