#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

// 素数判定 O(√n)
bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
  cout << setprecision(10);
  //素数列挙
  int N;
  cin >> N;
  vector<int> ans;
  for(int i = 5; i <= 55555; i+=2){
    if(isPrime(i)){
      if(i%5==1){
        ans.push_back(i);
      }
    }
    if(ans.size() == N){
      break;
    }
  }

  for(int i = 0; i < ans.size(); i++){
    if(i == ans.size()-1){
      cout << ans[i] << endl;
    } else {
      cout << ans[i] << " ";
    }
  }
}
