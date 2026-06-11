#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  ll A,B; cin >> A >> B;
  if(B%A==0){
    cout << B+A << endl;
  } else {
    cout << B - A << endl;
  }
}
