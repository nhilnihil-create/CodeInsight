#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000007
typedef long long int lint;

int main() {
  int N;
  cin >> N;
  bool ok = false;
  
  for(;N >= 0;){
    if(N%4 == 0){ok = true;}
    N -= 7;
  }
  if(ok){co("Yes");}
  else{co("No");}
}