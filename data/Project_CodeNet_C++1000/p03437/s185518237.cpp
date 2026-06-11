#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vi=vector<int>;  using vs=vector<string>; using gi=greater<int>;
#define soao(c) sort((c).begin(),(c).end()) //昇順
#define sodo(c) sort((c).begin(),(c).end(),gi()) //降順
#define rev(c) reverse((c).begin(), (c).end())

int main() {
  int X,Y; cin>>X>>Y;
  if(X%Y==0) cout<<"-1"<<endl;
  else cout<<X<<endl;
}
  
