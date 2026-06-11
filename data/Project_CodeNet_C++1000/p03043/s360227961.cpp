#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P= pair<int,int>;

int main() {
    ll N,K;
    cin>>N>>K;
    long double rate=0.0;
    for(int i=1;i<=N;i++){
      ll n=i;
      long double tmp=1.0/N;
      
      while(n<K){
        n*=2;
        tmp/=2;
        //cout<<n<<endl;
      }
      rate+=tmp;
    }
    
    cout<< fixed << setprecision(15) <<rate<<endl;
    return 0;
}