#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long,long>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n,k;
  cin >> n >> k;
  vector<pii> data(n);
  rep(i,n) cin >> data.at(i).second >> data.at(i).first;
  sort(data.begin(),data.end(),greater<pii>());
  long tmp = 0;
  set<int> st;
  vector<pii> list;
  rep(i,k){
    int t = data.at(i).second;
    int d = data.at(i).first;
    if(st.count(t)){
      list.push_back(data.at(i));
    }else{
      st.insert(t);
    }
    tmp += d;
  }
  long m = st.size();
  long ans = tmp + m*m;
  for(int i=k;i<n;i++){
    int nt = data.at(i).second;
    if(st.count(nt)) continue;
    if(list.size() == 0) break;
    int pd = list.at(list.size()-1).first;
    int nd = data.at(i).first;
    st.insert(nt);
    tmp = tmp - pd + nd;
    list.pop_back();
    m = st.size();
    ans = max(ans,tmp + m*m);
    if(st.size() == k) break;
  }
  cout << ans << endl;
}
