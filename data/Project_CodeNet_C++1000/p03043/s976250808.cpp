#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const ll INF=1e9;


int main(){
  int n,k;
  cin>>n>>k;

  double ans=0;

  rep1(i,n){//



    int x=0;
    int temp=i;
    double p=1;

    while(temp<k){
      x++;
      temp *=2;
      p *=double(0.5);
    }
    ans+= p;

  }

  ans /=double(n);
  printf("%.10lf",ans);




}
