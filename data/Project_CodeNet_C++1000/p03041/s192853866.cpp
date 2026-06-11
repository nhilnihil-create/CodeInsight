#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  int N, K;
  string S;
  cin >> N >> K >> S;
  
  S[K-1] = 'a' + (S[K-1]-'A');
    
  cout << S << endl;
  
  
  return 0;
}