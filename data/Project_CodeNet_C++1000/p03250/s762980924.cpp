#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int a,b,c;
    vector<int> vec(3);
    rep(i,3){
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int ans = vec.at(0) * 10 + vec.at(1);
    ans += vec.at(2);
    cout << ans << endl;

}