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
 vector<int>c(9);
 rep(i,9){
   cin>>c.at(i);
 }
 
 if(((c.at(1)-c.at(0))==(c.at(4)-c.at(3)))&&((c.at(1)-c.at(0))==(c.at(7)-c.at(6)))){
   //cout<<1<<endl;
   if((c.at(2)-c.at(1))==(c.at(5)-c.at(4))&&(c.at(2)-c.at(1))==(c.at(8)-c.at(7))){
     //cout<<2<<endl;
     if((c.at(3)-c.at(0))==(c.at(4)-c.at(1))&&(c.at(3)-c.at(0))==(c.at(5)-c.at(2))){
       //cout<<3<<endl;
       if((c.at(6)-c.at(3))==(c.at(7)-c.at(4))&&(c.at(6)-c.at(3))==(c.at(8)-c.at(5))){
         cout<<"Yes"<<endl;
         return 0;
       }
     }
   }
 }
 cout<<"No"<<endl;
}


