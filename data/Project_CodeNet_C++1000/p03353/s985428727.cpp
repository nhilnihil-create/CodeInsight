#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  string s;
  int K;
  cin >> s >> K;

  set<string> S;
  for(int i=0; i< s.length(); i++){
    for(int j=1; j <= K; j++){
      if(i+j-1 < s.length()){
        string sub = s.substr(i,j);
        S.insert(sub);
      }
    }
  }

  rep(i,K-1) {
    S.erase(S.begin());
  }

  cout << *S.begin() << endl;
}
