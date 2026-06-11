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
    int d[5];
    for(int i = 0 ; i < 5; i++){
        cin >> d[i];
    }
    int k;
    cin >> k;
    for(int i = 0 ; i < 4; i++){
        for(int j = i; j < 5;j++){
            if(abs(d[i]-d[j]) > k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}