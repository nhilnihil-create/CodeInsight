#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ll long long
#define ld long double
//vector<pair>のソート、firstが昇順、secondが降順
bool mycomp(pair<string,ll> a, pair<string,ll> b){if(a.first != b.first){return a.first < b.first;} if(a.second != b.second){return a.second > b.second;}else{return true;}}

int main(){
  ll n; cin >> n;
  vector<pair<string,ll>> p(n);
  rep(i,n){
    string s; ll nt;
    cin >> s >> nt;
    p.at(i) = make_pair(s,nt);
  }
  vector<pair<string,ll>> tmp; //ソート前のインデックスを保持する必要があるため、tmpにコピーする
  tmp = p;
  
  sort(begin(tmp),end(tmp),mycomp);
  
  ll i = 0;
  for(auto v : tmp){
    auto itr = find(p.begin(),p.end(),tmp[i]);
    cout << distance(p.begin(),itr) + 1 << endl;
    i++;
  }
}