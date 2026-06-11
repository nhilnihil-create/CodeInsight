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
    string s;
    cin >> s;
    int check[3];
    for(int i = 0; i < 3; i++) check[i] = 0;
    for(auto c : s){
        if(c == 'a') check[0] = 1;
        if(c == 'b') check[1] = 1;
        if(c == 'c') check[2] = 1;
    }
    bool flag = true;
    for(int i = 0; i < 3; i++){
        if(check[i] == 0) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
