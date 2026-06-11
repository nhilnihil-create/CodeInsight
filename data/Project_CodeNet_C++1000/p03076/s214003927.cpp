#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;


int main(){
    vector<pair<int,int>> dish(5);
    for(int i = 0; i < 5 ; i++){
        int a;
        cin >> a;
        dish[i].first = a % 10;
        if(dish[i].first != 0) dish[i].first = 10 - dish[i].first;
        dish[i].second = a;
    }
    sort(dish.begin(),dish.end());
    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans += dish[i].second + dish[i].first;
    }
    cout << ans - dish[4].first << endl;
    return 0;
}