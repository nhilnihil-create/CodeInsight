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
    vector<map<int,int>> m(N+1);
    vector<pair<int,int>> query(M);
    for(int i = 0; i < M ;i++){
        int pre,y;
        cin >> pre >> y;
        query[i] = make_pair(pre,y);
        p[pre].push(y);
    }
    for(int i = 1; i <= N;i++){
        if(p[i].empty()) continue;
        int k = p[i].size();
        for(int count = 1; count <= k; count++){
            m[i][p[i].top()] = count;
            p[i].pop();
        }
    }
    for(auto pa : query)
        printf("%06d%06d\n",pa.first,m[pa.first][pa.second]);
    return 0;
}