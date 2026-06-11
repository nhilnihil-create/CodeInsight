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
    int n,d,x;
    cin >> n >> d >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int num = 0;
    for(int i = 0; i < n; i++){
        int day = 1;
        while(day <= d){
            num++;
            day += a[i];
        }
    }
    cout << num + x << endl;
    return 0;
}
