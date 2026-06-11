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
    int n;
    cin >> n;
    for(int i = n; i <= 1111; i++){
        int first = i / 100;
        int second = i % 100 / 10;
        int third = i % 10;
        if(first == second && second == third){
            cout << 100 * first + 10 * second + third << endl;
            break;
        }
    }
    return 0;
}
