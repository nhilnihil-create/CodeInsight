#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,cnt = 0;
    int ans = 1000000;
    string s;
    cin >> N >> s;
    vector<int> e(N,0),w(N,0);

    rep(i,N){
        if(s[i] == 'E'){
            cnt++;
        }
        e[i] = cnt;
    }

    cnt = 0;

    rep(i,N){
        if(s[i] == 'W'){
            cnt++;
        }
        w[i] = cnt;
    }

    rep(i,N){
        ans = min(ans,w[i-1]+e[N-1]-e[i]);
    }

    cout << ans << endl;

    return 0;
}