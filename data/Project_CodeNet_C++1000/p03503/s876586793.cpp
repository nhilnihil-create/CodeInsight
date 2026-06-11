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
    int f[N][10];
    int cost[N][11];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            cin >> f[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j =  0; j < 11; j++){
            cin >> cost[i][j];
        }
    }
    int ans = -(INF_INT + 1);
    for(int bit = 1; bit < 1 << 10; bit++){
        int temp = bit;
        int count[N];
        memset(count,0,sizeof count);
        for(int i = 0; i < 10; i++){
            if(temp & 1){
                for(int j = 0; j < N; j++){
                    count[j] += f[j][i];
                }
            }
            temp >>= 1;
        }
        int tempans  = 0;
        for(int i = 0; i < N;i++){
            tempans += cost[i][count[i]];
        }
        ans = max(ans,tempans);
    }
    cout << ans << endl;
    return 0;
}
