#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
bool tv[100002][30];

int main(void){
    ll n, c;
    cin >> n >> c;

    rep(i, 0, n){
        ll tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp3--;
        rep(j, tmp1, tmp2 + 1){
            tv[j][tmp3] = true;
        }
    }

    ll sum = 0;
    rep(i, 1, 100002){
        ll num = 0;
        rep(j, 0, c){
            if(tv[i][j]) num++;
        }
        sum = max(num, sum);
    }

    cout << sum << endl;
    return 0;
}
