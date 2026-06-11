#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    string s;
    cin >> s;

    ll max_cnt = 0;
    ll cnt = 0;
    rep(i, s.size()){
        if(s.at(i) == 'A' || s.at(i) == 'C' || s.at(i) == 'G' || s.at(i) == 'T'){
            cnt++;
        }else{
            cnt = 0;
        }
        if(cnt > max_cnt){
            max_cnt = cnt;
        }
    }

    cout << max_cnt << endl;

}