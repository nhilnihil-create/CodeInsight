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
    vector<int> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int count = 0;
    int dis0 = a[2] - a[0];
    int dis1 = a[2] - a[1];
    if(dis0 % 2 == 0 && dis1 % 2 == 0){
        count += dis0 / 2 + dis1 / 2;
    }
    else if(dis0 % 2 == 1 && dis1 % 2 == 1){
        dis0--;dis1--;
        count++;
        count += dis0 / 2 + dis1 / 2;
    }
    else{
        int odd,even;
        if(dis0 % 2 == 0){
            even = dis0;
            odd = dis1;
        }
        else{
            even = dis1;
            odd = dis0;
        }
        count += 1 + even / 2 + (odd + 1) / 2;
    }
    cout << count << endl;
    return 0;
}
