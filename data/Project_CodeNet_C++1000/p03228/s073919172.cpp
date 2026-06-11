#include<iostream>
#include<list>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define chmin(a,b) (a>(b)?a=(b),1:0)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
typedef long int li;

void exchange(int& a, int& b,int flag){
  if(flag) swap(a,b);
  a/=2; b+=a;
  if(flag)swap(a,b);
}

int main(){
  int a,b,k; cin >>a >>b >>k;
  rep(i,k){
    exchange(a,b,i%2);
  }
  cout << a << " " << b << "\n";
}
