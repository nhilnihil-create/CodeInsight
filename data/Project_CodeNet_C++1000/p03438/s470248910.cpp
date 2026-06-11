#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

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
    vector<int> a(N);
    vector<int> b(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    bool res = false;
    ll needb = 0, sum = 0;
    for(int i = 0; i < N; i++){
        if(b[i] > a[i]){
            int temp = b[i] - a[i];
            if(temp % 2 == 1){
                needb += temp / 2 + 1;
                sum++;
            }
            else needb += temp / 2;
        }
        else sum += a[i] - b[i]; 
    }
    if(sum <= needb) res = true;
    else res = false;
    
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
