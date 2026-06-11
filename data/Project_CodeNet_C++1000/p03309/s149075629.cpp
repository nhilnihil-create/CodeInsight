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

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        ll b;
        cin >> b;
        a[i] = b - (i+1);
    }
    sort(a.begin(),a.end());
    ll x = a[N/2];
    ll res = 0;
    for(int i = 0; i < N; i++){
        res += abs(x - a[i]);
    }
    cout << res << endl;
    return 0;
}
