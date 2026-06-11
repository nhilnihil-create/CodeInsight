#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

struct res{
    string name;
    int score;
    int num;
}res_res[101];

bool comp(res a,res b){
    if(a.name != b.name){
        return a.name < b.name;
    }
    else{
        return a.score>b.score;
    }
}

int main() {

    int N;
    cin >> N;

    rep(i,N){
        cin >> res_res[i].name >> res_res[i].score;
        res_res[i].num = i+1;
    }

    sort(res_res,res_res+N,comp);

    rep(i,N){
        cout << res_res[i].num << endl;
    }

    // vector<pair<std::string,int>> vec;

    // int N;
    // cin >> N;

    // rep(i,N){
    //     string tmps;
    //     int tmpp;
    //     cin >> tmps >> tmpp;

    //     pair<std::string,int> p = make_pair(tmps,tmpp);

    //     vec.emplace_back(p);
    // }

    // sort(vec.begin(),vec.end());

    // for (auto V : vec) {
    //     cout << V.first << " " << V.second << endl;
    // }

}