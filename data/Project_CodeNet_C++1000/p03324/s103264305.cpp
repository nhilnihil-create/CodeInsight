#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  int N,K;
  cin >> N >> K;
  if(K==100){
    K = 101;
  }
  string ans = to_string(K);
  for(int i = 0; i < N; i++){
    ans += "00";
  }
  cout << ans << endl;
}

