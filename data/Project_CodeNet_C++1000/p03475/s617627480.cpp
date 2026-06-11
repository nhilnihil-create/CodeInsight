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
    int N;
    cin >> N;
    int C[N];
    int S[N];
    int F[N];
    for(int i = 1; i < N; i++){
        cin >> C[i] >> S[i] >> F[i];
    }
    vector<int> ans;
    for(int i = 1; i < N; i++){
        int time = S[i] + C[i];
        for(int j = i+1; j < N; j++){
            time = max(time,S[j]);
            int n = (time-1)/F[j] + 1 - S[j] / F[j] + 1;
            time = S[j] + F[j]*(n - 1) + C[j];
        }
        ans.emplace_back(time);
    }
    ans.emplace_back(0);
    for(int num : ans) cout << num << endl;
    return 0;
}
