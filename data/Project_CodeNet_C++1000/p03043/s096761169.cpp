#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,K;
  cin >> N >> K;
  double ans=0;
  for(int i=1;i<=N;i++){
    if(i>=K){
      ans+=(double)1/(double)N;
    }
    else if(i<K){
      int m=i;
      double pro=1;
      do{
        m*=2;
        pro/=(double)2;
      }while(m<K);
      ans+=pro/(double)N;
    }
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}