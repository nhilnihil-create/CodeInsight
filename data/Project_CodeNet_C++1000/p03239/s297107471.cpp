#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double pi = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

int main(){
    int n;
    cin >> n;
    int T;
    cin >> T;
    vector<pair<int,int>> p;
    for(int i = 0; i < n; i++){
        int c,t;
        cin >> c >> t;
        p.emplace_back(make_pair(c,t));
    }
    sort(p.begin(),p.end());
    for(int i = 0; i < n; i++){
        if(p[i].second <= T){
            cout << p[i].first << endl;
            return 0;
        }
    }
    cout << "TLE" << endl;
    return 0;
}
