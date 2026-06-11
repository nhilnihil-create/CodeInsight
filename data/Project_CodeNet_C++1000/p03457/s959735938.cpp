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
    int N;
    cin >> N;
    int time[N];
    int xy[N];
    int prex = 0,prey = 0,pretime = 0;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        time[i] = t - pretime;
        pretime = t;
        int a,b;
        cin >> a >> b;
        xy[i] = abs(prex - a) + abs(prey - b);
        prex = a;
        prey = b;
    }
    for(int i = 0; i < N; i++){
        if(time[i] < xy[i]){
            cout << "No" << endl;
            return 0;
        }
        else if(time[i] == xy[i]) continue;
        else if((time[i] - xy[i]) % 2 == 0) continue;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
