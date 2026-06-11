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
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int sum = a + b + c;
    int maxi = max(a,max(b,c));
    int minus = maxi;
    for(int i = 1; i <= k; i++) minus *= 2;
    cout << sum - maxi + minus << endl;
    return 0;
}
