#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

const int MAXN = 110000;

int memo[MAXN];

int dfs(int s){
    if(s == 0) return 0;
    if(memo[s] != -1) return memo[s];
    int res = s;
    for(int i = 1; i <= s; i*=6) res = min(res,dfs(s-i)+1);
    for(int i = 1; i <= s; i*=9) res = min(res,dfs(s-i)+1);
    return memo[s] = res;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < MAXN; i++) memo[i] = -1;
    cout << dfs(N) << endl;
    return 0;
}
