#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvs = vector<vector<string>>;

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
  vvs names(5);
  string tgt = "MARCH";
  rep(i,N){
    string name;
    cin >> name;
    rep(j,5){
      if(name[0]==tgt[j]){
        names[j].push_back(name);
      }
    }
  }

  for(int i=0;i<5;i++){
    for(int j=i+1;j<5;j++){
      for(int h=j+1;h<5;h++){
        ans += names[i].size()*names[j].size()*names[h].size();
      }
    }
  }
  printl(ans);
}
