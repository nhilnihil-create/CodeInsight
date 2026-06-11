#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int k;
    cin >> k;
    int ans = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i%2 == 0 && j%2 == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}