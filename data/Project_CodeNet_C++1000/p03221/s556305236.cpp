#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N,M;
  cin >> N >> M;

  map<int,string> order;
  map<string,string> ans;


  vector<vector<ll>> pref(N);

  for(int i = 0; i < M; i++){
    int tmp1;
    ll tmp2;
    cin >> tmp1 >> tmp2;

    pref[tmp1-1].push_back(tmp2);

    string key = to_string(tmp1) + "-" + to_string(tmp2);
    order[i] = key;
  }

  for(int i = 0; i < N; i++){
    if(pref.at(i).size() == 0) continue;

    sort(pref.at(i).begin(), pref.at(i).end());
    for(int j = 0; j < pref.at(i).size(); j++){
      int num = j + 1;
      string id = to_string(num);
      while(id.size() < 6){
        id = "0" + id;
      }
      id = to_string(i+1) + id;

      while(id.size() < 12){
        id = "0" + id;
      }

      string key = to_string(i+1) + "-" + to_string(pref.at(i).at(j));
      ans[key] = id;
    }
  }

  for(int i = 0; i < M; i++){
    cout << ans[order[i]] << endl;
  }
}

