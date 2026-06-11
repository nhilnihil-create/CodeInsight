#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
using tiil = tuple<int,int,ll>;

const ll modSeed = pow(10,9) + 7;
const int INF = 1'000'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll N,ans;

int main(){
  ans = 0;
  cin >> N;
  vector<tiil> info(N);
  tiil defo;
  rep(i,N){
    int x,y;
    ll h;
    cin >>x>>y>>h;
    info[i] = make_tuple(x,y,h);
    if(h!=0) defo=info[i];
  }
  for(int x=0;x<=100;x++){
    for(int y=0;y<=100;y++){
      int range = abs(get<0>(defo)-x)+abs(get<1>(defo)-y);
      ll height = get<2>(defo) + range;
      bool flg = true;
      for(int i=0;i<N;i++){
        ll cHeight = max(height-abs(get<0>(info[i])-x)-abs(get<1>(info[i])-y),0LL);
        if(cHeight!=get<2>(info[i])){
          flg = false;
        }
      }
      if(flg){
        cout << x << " " << y << " " << height;
        return 0;
      }
    }
  }
}
