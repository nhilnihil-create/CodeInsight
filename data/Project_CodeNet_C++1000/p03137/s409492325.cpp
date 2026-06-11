#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int main(){
    int N,M;cin>>N>>M;
    vec_int X(M);
    rep(i,M)cin>>X.at(i);

    if(M<=N){
        cout<<0<<endl;
        return 0;
    }
    //N<Mの場合に限定
    //明らかに最初にN個はM個のうちのどこかに置くことになる
    //残りのN-M個になるけれど、移動距離が最短になるN-M個を動かすように制度設計をすればよい。

    //Xをソートする
    sort(X.begin(),X.end());
    //M-1個の距離のベクトルを求める

    vec_int D(M-1);
    rep(i,M-1){
        D.at(i)=X.at(i+1)-X.at(i);
    }

    //Dをソートする
    sort(D.begin(),D.end());

    //Dの最初のN-M個が求める答え

    int tot = 0;
    rep(i,M-N){
        tot+=D.at(i);
    }

    cout<<tot<<endl;








    return 0;
}