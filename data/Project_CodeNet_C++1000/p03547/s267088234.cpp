#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long X=1000000000+7;

int main() {
  char x,y;
  cin>>x>>y;
  if(x>y) cout<<">"<<endl;
  else if(x<y) cout<<"<"<<endl;
  else cout<<"="<<endl;
}