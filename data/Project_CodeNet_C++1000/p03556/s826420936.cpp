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
    int N;
    cin >> N;
    int pre = 0;
    for(int i = 1; i <= sqrt(N); i++){
        if(i*i < N) pre = i*i;
        if(i*i == N) {
            pre = i*i;
            break;
        }
        if(i*i > N) break;
    }
    cout << pre << endl;
    return 0;
}
