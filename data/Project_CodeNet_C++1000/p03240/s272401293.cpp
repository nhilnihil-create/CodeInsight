
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
// set<int>st{ 3,1,4,1,5,9,2,6,5,3,5 };
//     for (auto itr = st.begin(); itr != st.end(); ++itr) {
//         cout << *itr;
//     }
#include <bits/stdc++.h>
#include <regex>
using namespace std;
using ll = int64_t;
using P = pair<int,int>;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(3));
    rep(i,n){
      cin>>vec.at(i).at(0)>>vec.at(i).at(1)>>vec.at(i).at(2);
    }
    int hc=-1;
    int h;
    int x,y;
    x=-1;
    y=-1;
    rep(i,101){
        rep(j,101){
            rep(k,n){
                if(vec.at(k).at(2)!=0){
                    hc=abs(vec.at(k).at(0)-i);
                    hc+=abs(vec.at(k).at(1)-j);
                    hc+=vec.at(k).at(2);
                    //cout<<i<<j<<k<<hc<<endl;
                    rep(m,n){
                    h=abs(vec.at(m).at(0)-i);
                    h+=abs(vec.at(m).at(1)-j);
                    h=hc-h;
                    h=max(h,0);
                    if(h!=vec.at(m).at(2)){
                        hc=-1;
                        goto SKIP; }}
                x=i;
                y=j;
                cout<<x<<" "<<y<<" "<<hc<<endl;
                return 0;}
                SKIP:;
                
            }

        }
    }
    
}

