#include<bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
//using namespace atcoder;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  double a,b;
  cin >> a >> b;
  cout << ceil((a+b)/2) << endl;

  return 0;
}