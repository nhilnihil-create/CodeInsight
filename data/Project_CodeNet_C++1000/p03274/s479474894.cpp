#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> can(N);
    for(int i = 0; i < N; i++) cin >> can[i];
    int l = 0, r = K-1;
    int cost = INF_INT;
    while(r < N){
        cost = min(cost,min(abs(can[l]) + abs(can[l] - can[r]),abs(can[r]) + abs(can[l] - can[r])));
        l++;r++;
    }
    cout << cost << endl;
    return 0;
}
