#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    //Wの数とSの数の累積和を計算
    vector<int> W_cs(n,0);
    vector<int> E_cs(n,0);
    rep(i,n){
        if(i==0){
            if(s.at(i)=='W') W_cs.at(i) = 1;
            else E_cs.at(i) = 1;
        }
        else{
            W_cs.at(i) = W_cs.at(i-1);
            E_cs.at(i) = E_cs.at(i-1);
            if(s.at(i)=='W') W_cs.at(i) += 1;
            else E_cs.at(i) += 1;
        }
    }
    // rep(i,n){
    //     cout<<W_cs.at(i)<<" ";
    // }
    // cout<<endl;
    // rep(i,n){
    //     cout<<E_cs.at(i)<<" ";
    // }
    // cout<<endl;

    //処理
    int ans=0;//向きを直す人数
    int ans_max=0;
    rep(p,n){
        if(p==0){
            if(s.at(p)=='W') ans = E_cs.at(n-1);
            else ans = E_cs.at(n-1) - 1;
            ans_max = ans;
        }
        else{
            if(s.at(p)=='W'){
                ans = E_cs.at(n-1) - E_cs.at(p) + W_cs.at(p) -1;
            }
            else ans = E_cs.at(n-1) - E_cs.at(p) + W_cs.at(p);
        }
        // cout<<ans<<endl;
        if(ans_max>ans) ans_max = ans;
    }

    cout<<ans_max<<endl;
    return 0;
}