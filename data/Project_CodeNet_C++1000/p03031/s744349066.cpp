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
    int N,M;
    cin >> N >> M;
    int check[M][N];
    for(int i = 0 ; i < M; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int s;
            cin >> s;
            s--;
            check[i][s] = 1;
        }
    }
    vector<int> bi(M);
    for(int i = 0; i < M; i++) cin >> bi[i];
    int cnt = 0;
    for(int bit = 0; bit < 1 << N; bit++){
        int temp = bit;
        vector<int> swi;
        int ind = 0;
        while(temp > 0){
            if(temp & 1) swi.emplace_back(ind);
            ind++;
            temp >>= 1;
        }
        vector<int> on(M,0);
        for(auto m : swi){
            for(int i = 0; i < M; i++){
                if(check[i][m] == 1) on[i]++; 
            }
        }
        bool res = true;
        for(int i = 0; i < M; i++){
            if(on[i] % 2 != bi[i]) res = false;
        }
        if(res) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
