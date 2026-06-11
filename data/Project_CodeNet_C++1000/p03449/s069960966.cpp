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
    int n;
    cin >> n;
    vector<int> one(n);
    vector<int> two(n);
    cin >> one[0];
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        one[i] = one[i-1] + a;
        two[i] = 0;
    }
    cin >> two[0];
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        for(int j = 0; j <= i; j++){
            two[j] += a;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        int temp = one[i] + two[i];
        sum = max(temp,sum);
    }
    cout << sum << endl;
    return 0;
}
