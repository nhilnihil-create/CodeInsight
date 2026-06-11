#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int a,b,c;
  cin >> a>>b>>c;
  int p=max(a,max(b,c));
  int q=max(a,max(b,c))+1;
  if((3*p-(a+b+c))%2==0){
    cout <<(3*p-(a+b+c))/2;
  }else{
    cout << (3*q-a-b-c)/2;
  }
}
