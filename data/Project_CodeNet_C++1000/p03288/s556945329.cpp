#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int r;
    cin >> r;
    if(r < 1200){
        cout << "ABC" << endl;
    }else if(r < 2800){
        cout << "ARC" << endl;
    }else {
        cout << "AGC" << endl;
    }
}