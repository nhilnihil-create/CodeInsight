#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    string s;
    cin >> s;
    int a = (s[0]-'0')*10 + (s[1]-'0');
    int b = (s[2]-'0')*10 + (s[3]-'0');
    if(1<= b && b <= 12 && 1<= a && a <= 12){
        cout << "AMBIGUOUS" << endl;
    }else if(1<= b && b <= 12){
        cout << "YYMM" << endl;
    }else if(1<= a && a <= 12){
        cout << "MMYY" << endl;
    }else{
        cout << "NA" << endl;
    }
}