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
    string ans = string();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char c;
            cin >> c;
            if(i == j) ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}
