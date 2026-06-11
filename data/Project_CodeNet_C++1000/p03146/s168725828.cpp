#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main(){
  int s;
  cin>> s;

  set<int> st;
  int ans = 1;
  while(true){
    if(st.find(s) != st.end()){
      cout << ans << endl;
      return 0;
    }
    st.insert(s);
    if(s%2 == 0) s/=2;
    else s = s*3+1;
    ans++;
  }


}

