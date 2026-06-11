#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    rep(i, n){
        int num = i+1;
        if(num%2 == 0) continue;
        int div_cnt = 0;
        rep(j, num){
            int divider = j+1;
            if(num%divider == 0) div_cnt++;
        }
        if(div_cnt == 8) ++cnt;
    }
    cout << cnt << endl;
}
