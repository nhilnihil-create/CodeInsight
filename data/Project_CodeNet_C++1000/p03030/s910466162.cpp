#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


//tupleの利用
//昇順ソート，降順ソートを入れ替えるときは． -　を入れるとよい

int main(){
  int n;
  cin >> n;
  vector<tuple <string, int,int>>shop;
  //--------- <name, price, id>
  REP(i,n){
    string s;
    int p, id;
    cin >> s >> p;
    p = - p;  // 昇順sort <->　降順 sortを入れ替えるため
    id = i + 1;
    shop.push_back(tie(s,p,id));  //tupleに格納　push_back(tie(a, b, c));
  }

  sort(ALL(shop)); //s,p, idの優先順位でsortされる

  REP(i,n){
    cout << get<2>(shop[i]) << endl;  //値の参照　get<要素数>(配列名[index])
  }
  return 0;
}
