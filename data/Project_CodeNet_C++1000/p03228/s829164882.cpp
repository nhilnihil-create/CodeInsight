#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll A,B,K;
  cin >> A >> B >> K;

  for(int i = 0; i < K; i++){
    if(i%2==0){
      ll tmpa;
      if(A%2==0){
        tmpa = A / 2;
        A -= tmpa;
      } else { 
        A -= 1;
        tmpa = A / 2;
        A -= tmpa;
      }
      B += tmpa;
    } else { 
      ll tmpb;
      if(B%2==0){
        tmpb = B / 2;
        B -= tmpb;
      } else { 
        B -= 1;
        tmpb = B / 2;
        B -= tmpb;
      }
      A += tmpb;
    }
  }

  cout << A << " " << B << endl;
}

