#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<=(n);++i)
using namespace std;
using ll = long long;
using P= pair<int,int>;

int main() {
    
    int N,Y;
    
    cin>>N>>Y;
    rep(i,N){
      for(int t=0;t<=N-i;t++)
      {
        if((9*i+4*t+N)==(Y/1000)){
          cout<<i<<" "<<t<<" "<<N-i-t<<endl;
          return 0;
        }
      }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}