#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S; cin >> S;
  if(S.size() == 3){
    reverse(S.begin(), S.end());
  }
  cout << S << endl;
}
