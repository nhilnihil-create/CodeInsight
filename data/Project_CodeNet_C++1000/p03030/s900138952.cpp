#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    int n;
    cin>>n;
    vector<tuple<string,int,int>> temp;
    rep(i,n){
        string s;
        int p;
        cin>>s>>p;
        //tupleのソートでstringとintを降順に並び替えるので点数にマイナスをかけ高い順に取り出す
        temp.push_back(make_tuple(s,-1*p,i+1));
    }
    sort(temp.begin(),temp.end());
    rep(i,n) cout<<get<2>(temp[i])<<endl;
    return 0;
}