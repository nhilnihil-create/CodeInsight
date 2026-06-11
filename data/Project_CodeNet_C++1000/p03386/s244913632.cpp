#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  int A, B, K; cin >> A >> B >> K;
  vector<bool> chk(B+1,0);
  int count=0;
  for(int i=A; i<=B; i++){
    chk[i]=1;
    count++;
    if(count == K) break;
  }
  count = 0;
  for(int i=B; i>=A; i--){
    if(chk[i]) break;
    chk[i]=1;
    count++;
    if(count == K) break;
  }
  
  for(int i=A; i<=B; i++){
    if(chk[i]) cout << i << endl;
  }
  
}
  