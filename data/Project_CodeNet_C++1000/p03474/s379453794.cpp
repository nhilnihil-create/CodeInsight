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
    int A,B;
    cin >> A >> B;
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 0;i < s.size(); i++){
        if(i < A || i > A){
            if('0' <= s[i] && s[i] <= '9') continue;
            else flag = false;
        }
        else if(s[i] != '-') flag = false; 
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
