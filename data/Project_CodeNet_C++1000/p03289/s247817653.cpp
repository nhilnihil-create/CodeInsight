#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 1e18LL

const ll MAX = 1000000000000000000; //1e18

int main(){
    string s;
    cin >> s;
    bool exist = true;
    int cnt = 0;
    int n = s.size();
    rep(i, n){
        if(i == 0){
            if(s[i] != 'A') exist = false;
        }else if(2 <= i && i <= n-2){
            if(s[i] == 'C') cnt++;
        }else{
            if('a' <= s[i] && s[i] <= 'z'){
                continue;
            }else{
                exist = false;
            }
        }
    }
    if(exist && cnt == 1) cout << "AC" << endl;
    else cout << "WA" << endl;
}

