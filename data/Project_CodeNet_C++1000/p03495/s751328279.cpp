//auto 関数名 = [(&:ラムダ外の引数をとる時))](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 関数の処理 }; //inside main() define function. take care of };
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }
// sort(配列変数.begin(), 配列変数.end());
// do {
//   // 順列に対する処理
// } while (next_permutation(配列変数.begin(), 配列変数.end()));
//const double PI = acos(-1); M_PI
// cout << fixed << setprecision(10);
#include <bits/stdc++.h>
#include <regex>
using namespace std;
using ll = int64_t;
using P = pair<int,int>;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
  int n,k;
  cin>>n>>k;
  map<int,int> m;
  int a;
  rep(i,n){
    cin>>a;
    m[a]=m[a]+1;
    //cout<<m[a]<<endl;
  }
  vector<int>vec;
  for(auto p:m){
    auto v=p.second;
    vec.push_back(v);
  }
  sort(all(vec));
  int cnt=0;
  int ans=0;
  rep(i,n){
    if((int)(vec.size())-cnt<=k){
      cout<<ans<<endl;
      return 0;
    }else{
      cnt+=1;
      ans+=vec.at(i);
    }
  }
}


