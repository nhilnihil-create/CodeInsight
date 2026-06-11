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
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    int count = 0;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int m = 0; m <= c; m++){
                if(x == i * 500 + j * 100 + m * 50) count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
