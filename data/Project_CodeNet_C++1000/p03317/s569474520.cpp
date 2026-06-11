#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  int N,K; cin >> N >> K;
  int ans;
  if( (N-1) % (K-1) == 0){
    ans = (N-1) / (K-1);
  } else { 
    ans = (N-1) / (K-1) + 1;
  }
  cout << ans << endl;
}
