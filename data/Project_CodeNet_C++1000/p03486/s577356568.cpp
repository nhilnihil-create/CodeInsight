#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;

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
    string s,t;
    cin >> s >> t;
    vector<char> _s(s.length());
    vector<char> _t(t.length());
    for(int i = 0; i < s.length(); i++) _s[i] = s[i];
    for(int i = 0; i < t.length(); i++) _t[i] = t[i];
    sort(_s.begin(),_s.end());
    sort(_t.begin(),_t.end(),greater<>());
    int flag = 0;
    for(int i = 0; i < min(s.length(),t.length()); i++){
        if(_s[i] > _t[i]){
            flag = -1;
            break;
        }
        if(_s[i] < _t[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 1) cout << "Yes" << endl;
    else if(flag == 0 && s.length() < t.length()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
