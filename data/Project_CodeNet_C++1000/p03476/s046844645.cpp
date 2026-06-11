#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;


int main(){
  long q,m=100010;
  cin >> q;
  vector<long> d(m,0),dd(m,0),rui(m,0);
  for(int i=2;i<m/2;i++){
    long tmp = 2;
    while(i*tmp < m){
      d[i*tmp] = 1;
      tmp++;
    }
  }
  for(int i=2;i<m;i++){
    if(i%2 == 1 && d[i] == 0 && d[(i+1)/2] == 0)dd[i] = 1;
  }
  rep(i,m-1)rui[i+1] = rui[i] + dd[i+1];
  rep(i,q){
    long l,r;
    cin >> l >> r;
    cout << rui[r]-rui[l-1] << endl;
  }
  return 0;
}