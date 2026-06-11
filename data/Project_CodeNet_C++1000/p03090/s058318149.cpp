#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
bool path[105][105];

int main(void){
    ll n;
    cin >> n;

    ll sum;
    if(n % 2 == 0){
        sum = n + 1;
    }else{
        sum = n;
    }

    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            if(i == j) continue;
            if(i + j == sum) continue;
            path[i][j] = true;
            path[j][i] = true;
        }
    }

    ll count = 0;
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            if(path[i][j]){
                count++;
                path[j][i] = false;
            }
        }
    }

    cout << count << endl;
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            if(path[i][j]){
                cout << i << " " << j << endl;
            }
        }
    }
}
