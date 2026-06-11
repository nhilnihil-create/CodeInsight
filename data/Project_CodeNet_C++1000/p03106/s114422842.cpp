
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
using namespace std;
#define _GLIBCXX_DEBUG /GCC環境下で[]による配列要素参照のエラーを出す
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  if(a>b){
    swap(a,b);}
  vector<int> vec(a);
  for(int i=1;i<=a;i++){
    if((a%(i)==0)&&(b%(i)==0)){
      vec.push_back(i);
    }}
 reverse(all(vec));
 cout<<vec.at(k-1)<<endl;
}