#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    rep(i, n-1){
        if(s[i] != s[i+1]) continue;
        else{
            cnt++;
            if(s[i+1] == '1'){
                s[i+1] = '0';
            }else{
                s[i+1] = '1';
            }
        }
    }
    cout << cnt << endl;
}