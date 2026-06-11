#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K; 
  
  if(A <= B){
    vector<int> c(A);
    for(int i = 1; i <= A; i++){
      if(A % i == 0 && B % i == 0){
        c.at(i - 1) = i;
      }
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int d = c.at(K - 1);
    cout << d << endl;
  }
  else{
    vector<int> c(B);
    for(int i = 1; i <= B; i++){
      if(A % i == 0 && B % i == 0){
        c.at(i - 1) = i;
      }
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int d = c.at(K - 1);
    cout << d << endl;
  }
}