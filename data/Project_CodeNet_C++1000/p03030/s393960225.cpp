
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

using P=pair<int,int>;
int main(){
    int n;
    cin >> n;
    //コンテナはmapとし、キー＝都市名、pairのfirst=点数、pairのsecond=番号とする
    map<string, vector<P>> mp;
    rep(i,n){
        string s;
        int p;
        cin >> s >> p;
        //map.find(x)はxと等価なキーの要素を検索する
        //map.find()はキーが見つからない場合にはendを返す
        //つまり!=mp.end()は「すでにその市があるなら」という意味
        if(mp.find(s) != mp.end()){
            mp[s].push_back(P(p,i+1));
        }
        else{
            mp[s]=vector<P>{P(p,i+1)};
        }
    }
    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        //->は関節メンバ演算子 ドットと大体同じ
        sort(mp[itr->first].rbegin(),mp[itr->first].rend());
        for(P x:mp[itr->first]){
            cout << x.second << endl;
        }
    }

    return 0;
}