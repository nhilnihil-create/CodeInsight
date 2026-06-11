#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  int K;
  ll A,B;
  cin >> A >> B >> K;
  map<ll,int> ans;
  ll max_val = B;
  ll min_val = A;
  
  for(int i = 0; i < K; i++){
    ans[A]++;
    A++;
    if(A > max_val) break;
  }
  for(int i = 0; i < K; i++){
    ans[B]++;
    B--;
    if(B < min_val) break;
  }
  for(auto x: ans){
    cout << x.first << endl;
    
  }
}

