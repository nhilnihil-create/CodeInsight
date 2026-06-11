#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;


int main(){
    double t,x;
    cin >> t >> x;
    double ans = t / x;
    printf("%.12lf\n",ans);
    return 0;
}