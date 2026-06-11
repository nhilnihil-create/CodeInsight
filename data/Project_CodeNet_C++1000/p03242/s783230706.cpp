#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double pi = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

int main(){
    string n;
    cin >> n;
    for(int i = 0; i < n.length(); i++){
        if(n[i] == '1') n[i] = '9';
        else n[i] = '1' ;
    }
    cout << stoi(n) << endl;
    return 0;
}
