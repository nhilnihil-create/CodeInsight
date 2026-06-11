#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){
    string s; cin >> s;
    int cnt = 0, ans = 0;
    for (auto si: s){
        if (si == 'A' || si == 'C' || si == 'G' || si == 'T'){
            cnt ++;
        }
        else{
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    cout << max(ans, cnt) << endl;
}