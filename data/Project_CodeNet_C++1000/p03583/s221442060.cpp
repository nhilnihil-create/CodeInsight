#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  ll N;
  cin>>N;
  for(ll h=1;h<=3500;h++){
    for(ll n=1;n<=3500;n++){
      ll b=N*h*n;
      ll a=4*h*n-N*n-N*h;
      if(a>0&&b%a==0){
	printf("%d %d %d\n",h,n,b/a);
	return 0;
      }
    }
  }
  return 0;
}