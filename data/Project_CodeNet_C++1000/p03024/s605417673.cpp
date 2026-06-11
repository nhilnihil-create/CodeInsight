#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
const ll MOD = 1000000007;
int main(){
  string Z;
  cin>>Z;
  int cnt=0;
  for(int i=0;i<Z.size();i++){
    if(Z[i]=='o')cnt++;
  }
  if(cnt+(15-Z.size())>=8)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
