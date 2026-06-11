#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int p=max(max(a,b),c);
  p*=3;
  int sum=a+b+c;
  int ans=0;
  while((p-sum)%2==1){
    p+=3;
  }
  cout << (p-sum)/2;
}
    