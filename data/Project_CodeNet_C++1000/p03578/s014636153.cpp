#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  int N;
  cin >> N;
  map<ll,int> stock;
  for(int i =0; i < N; i++){
    ll tmp;
    cin >> tmp;
    stock[tmp]++;
  }
  int M;
  cin >> M;
  map<ll,int> need;

  for(int i = 0; i < M; i++){
    ll tmp;
    cin >> tmp;
    need[tmp]++;
  }
  
  bool flg = true;
  for(auto x: need){
    // stock に x.firstがx.second以上あればOK
    if(stock.count(x.first) == 0){
      flg = false;
      break;
    } else {
      if(x.second <= stock[x.first]){
        continue;
      } else {
        flg = false;
        break;
      }
    }
  }
  cout << (flg ? "YES" : "NO") << endl;
}

