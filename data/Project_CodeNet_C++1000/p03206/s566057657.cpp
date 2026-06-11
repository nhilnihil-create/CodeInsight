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
    int d;
    cin >> d;
    if(d == 25) cout << "Christmas" << endl;
    if(d == 24) cout << "Christmas Eve" << endl;
    if(d == 23) cout << "Christmas Eve Eve" << endl;
    if(d == 22) cout << "Christmas Eve Eve Eve" << endl; 
    return 0;
}