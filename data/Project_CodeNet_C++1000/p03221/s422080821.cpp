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
    int N,M;
    cin >> N >> M;
    vector<priority_queue<int,vector<int>,greater<int>>> p(N+1);
    vector<map<int,string>> m(N+1);
    vector<pair<int,int>> query(M);
    for(int i = 0; i < M ;i++){
        int pre,y;
        cin >> pre >> y;
        query[i] = make_pair(pre,y);
        p[pre].push(y);
    }
    for(int i = 1; i <= N;i++){
        if(p[i].empty()) continue;
        string pre = to_string(i);
        int n = pre.size();
        for(int j = 1; j <= 6-n; j++) pre = "0" + pre;
        int k = p[i].size();
        for(int count = 1; count <= k; count++){
            string after = to_string(count);
            int n = after.size();
            for(int j = 1; j <= 6-n; j++) after = "0" + after;
            string comp = pre + after;
            m[i][p[i].top()] = comp;
            p[i].pop();
        }
    }
    for(auto pa : query){
        cout << m[pa.first][pa.second] << endl;
    }
    return 0;
}