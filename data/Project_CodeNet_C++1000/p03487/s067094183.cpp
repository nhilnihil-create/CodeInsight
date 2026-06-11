#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

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
    map<int,int> m;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        m[a] = m[a] + 1;
    }
    int count = 0;
    for(auto ite = m.begin(); ite != m.end(); ite++){
        if(ite -> first > ite -> second) count += ite -> second;
        if(ite -> first < ite -> second) count += ite -> second - ite -> first;
    }
    cout << count << endl;
    return 0;
}
