#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    //バケット法
    //値とインデックスを対応させる.
    vector<int> bucket(n+1);
    rep(i,n) ++bucket.at(a.at(i));

    //ソート
    sort(bucket.begin(),bucket.end());
    reverse(bucket.begin(),bucket.end());
    // rep(i,n) cout<<bucket.at(i)<<endl;

    //変える必要があるか？
    int group=0;
    int ans=0;
    rep(i,n){
        if(bucket.at(i)!=0) ++group;
    }
    if(group<=k){
        cout<<0<<endl;
        return 0;
    }
    else{
        int del_group = 0;
        del_group = group - k;
        reverse(bucket.begin(),bucket.end());

        int t;
        rep(i,n){
            if(bucket.at(i)!=0){
                ans += bucket.at(i);
                ++t;
                if(t==del_group) break;
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}