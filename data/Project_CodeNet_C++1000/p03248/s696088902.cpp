#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  string S;
  cin>>S;
  int l = S.size();
  bool can = true;
  if(S[l-1]=='1') can = false;
  S.erase(S.end()-1);
  l--;
  for(int i = 0; i < l; i++) {
    if(S[i]!=S[l-1-i]) can=false;
  }
  if(S[0]=='0') can = false;
  if(!can) cout<<-1<<endl;
  if(can){
    int parent = 0;
    int cnt = 1;
    for(int i = 0; i < l; i++){
      if(S[i]=='0') {
        cout<<parent+1<<" "<<cnt+1<<endl;
        cnt++;
      }
      if(S[i]=='1'){
        cout<<parent+1<<" "<<cnt+1<<endl;
        parent = cnt;
        cnt++;
      }
    }
  }
}