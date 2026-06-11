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
using ll = long long;
using P = pair<int,int>;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
 int n;
 cin>>n;
 int cnt;
 int min=10000;
 for(int i=1;i<n/2+1;i++){
     int j=n-i;
     cnt=0;
     cnt+=i/100000+(i%100000)/10000+(i%10000)/1000+(i%1000)/100+(i%100)/10+i%10;
     cnt+=j/100000+(j%100000)/10000+(j%10000)/1000+(j%1000)/100+(j%100)/10+j%10;
     if(cnt<min){
       min=cnt;
     } 
   }
 cout<<min<<endl;
}

