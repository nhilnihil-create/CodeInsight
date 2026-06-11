#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll num = 0;
    ll cnt = 0;
    for(ll i = n-1; i >= 0; i--){
        if(s[i] == 'B'){
            cnt += num;
        }else{
            num++;
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
bwbwbw
bwbwwb
bwwbwb
bwwwbb
wbwwbb
wwbwbb
wwwbbb
*/