#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;

const long long MOD = 1e9 + 7;
const long long INF = 1e12;
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
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> subsum(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    subsum[0] = a[0];
    for(int i = 1; i < N; i++){
        subsum[i] = subsum[i-1] + a[i];
    }
    sort(subsum.begin(),subsum.end());
    ll cnt = 0;
    for(int i = 0; i < N; i++){
        if(subsum[i] == 0) cnt++;
    }
    ll pre = subsum[0];
    ll nowcnt = 1;
    for(int i = 1; i < N; i++){
        if(pre == subsum[i]) nowcnt++;
        else{
            cnt +=  nowcnt * (nowcnt - 1) / 2;
            pre = subsum[i];
            nowcnt = 1;
        }
    }
    cout << cnt + nowcnt * (nowcnt - 1) / 2 << endl;
    return 0;
}
