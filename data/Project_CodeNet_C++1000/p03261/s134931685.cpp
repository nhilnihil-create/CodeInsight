#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>//long long型の最大値(LLONG_MAX)など
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;
typedef long double lb;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)


int main() {
    ll N;
    cin >> N;
    vector<string> W(N);
    rep(i,N){
        cin >> W[i];
    }

    map<string,ll> countSiritori;
    bool ans = true;
    rep(i,N){
        if(countSiritori[W[i]] == 1){
            ans = false;
            break;
        }else{
            countSiritori[W[i]] = 1;
        }

        if(i != 0){
            if(W[i].at(0) != W[i-1].at(W[i-1].size()-1)){
                ans = false;
                break;
            }
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

