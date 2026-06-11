#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

//写経

int main(){
  int M,K;cin >> M >> K;
  vector<int> V;
  int num = 0;
  
  //コーナーケース
  if(M == 1 && K == 1){
    cout << -1 << endl;
    return 0;
  }
  if(M == 1 && K == 0){
    cout << "0 0 1 1" << endl;
    return 0;
  }
  if(K>=(1<<M)){ //kが長さ2のM乗(1bitシフトで2乗)をオーバー
    cout << -1 << endl;
    return 0;
  }

  rep(i,1<<M) if(i!=K) cout << i << " ";
  cout << K << " ";
  for(int j=(1<<M)-1;j>=0;j--) if(j!=K) cout << j << " ";
  cout << K;
  cout << endl;
  
  
  
}