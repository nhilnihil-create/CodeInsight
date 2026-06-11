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
    int N,H;
    cin >> N >> H;
    vector<pair<int,int>> d;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        d.emplace_back(make_pair(a,1));
        d.emplace_back(make_pair(b,0));
    }
    sort(d.begin(),d.end(),greater<>());
    int index = 0;
    int count = 0;
    while(H > 0){
        int damage = d[index].first;
        int check = d[index].second;
        if(check == 0){
            H -= damage;
            count++;
            index++;
        }
        else break; 
    }
    if(H > 0) count += (H-1) / d[index].first + 1;
    cout << count << endl;
    return 0;
}
