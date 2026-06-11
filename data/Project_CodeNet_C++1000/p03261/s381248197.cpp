#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    int n;
    cin >> n;
    vector<string> words;
    bool ans = true;
    rep(i,n){
        string w;
        cin >> w;
        words.push_back(w);
        //これまでに出ていないか
        rep(j,i){
            if(words[j] == w){
                ans = false;
            }
        }
        //単語が重複していないか
        if(i == 0) continue;
        if(words[i-1][words[i-1].size()-1] != w[0]){
            ans = false;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}
/*

ルールを一つずつ確認すればオーケー
単語が重複していないかは、O(N^2)でやったが、
sortすればO(NlogN)で確認できる
今回は1 <= N <= 100なので十分間に合う

*/