#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;
typedef pair<int,int> P;

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
    int N,M;
    cin >> N >> M;
    int ans = 1;
    for(int i = 1; i <= M; i++) ans *= 2;
    int temp = ans;
    ans *= 1900 * M;
    for(int i = 1; i <= temp; i++) ans += (N-M)*100;
    cout << ans << endl;
    return 0;
}
