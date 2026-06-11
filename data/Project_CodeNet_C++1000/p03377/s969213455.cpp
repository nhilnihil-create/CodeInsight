#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll A,B,X;
  cin >> A >> B >> X;
  if(X >= A && X <= A+B){
    cout << "YES" << endl;
  } else{
    cout << "NO" << endl;
  }
}
