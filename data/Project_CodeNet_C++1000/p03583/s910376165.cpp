#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  ll N;
  cin>>N;
  bool flag=false;
  for(int h=1;h<=3500;h++){
    for(int n=1;n<=3500;n++){
      ll x=h*n*N;
      ll y=4*h*n-N*(n+h);
      if(y==0){
        continue;
      }
      if(x%y==0&&x/y>0){
        cout<<h<<" "<<n<<" "<<x/y<<endl;
        flag=true;
        break;
      }
    }
    if(flag){
      break;
    }
  }
}
