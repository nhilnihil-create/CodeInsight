#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const long long INF=1e9+5;
const string alp="abcdefghijklmnopqrstuvwxyg"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYG";
typedef long long ll;

int main() {
  ll N,Y;
  cin>>N>>Y;
  ll a=-1,b=-1,c=-1;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N-i;j++){
      ll k=N-i-j;
      if(10000*i+5000*j+1000*k==Y){
        a=i;
        b=j;
        c=k;
        break;
      }
    }
  }
  cout<<a<<" "<<b<<" "<<c<<endl;
}
