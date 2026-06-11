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
    int n;
    cin >> n;
    int ans[n+1];
    vector<pair<int,int>> seq(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        seq[i] = make_pair(a,i);
    }
    sort(seq.begin(),seq.end(),greater<>());
    int left = seq[n/2-1].first;
    int right = seq[n/2].first;
    for(int i = 0; i < n; i++){
        if(i < n / 2){
            ans[seq[i].second + 1] = right;
        }
        else{
            ans[seq[i].second + 1] = left;
        }   
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}
