#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep1(i,n) for(int i = 1;i < n;i++)
#define co(x) cout << x << endl
#define cosp(x) cout << x << " "
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll ans = 0;
    bool flag = true;
    int tmpi,tmpj;

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(j - k <0) tmpj = j - k + n;
                else tmpj = j - k;
                if(i - k < 0) tmpi = i - k + n;
                else tmpi = i - k;
                if(s[i][tmpj] != s[j][tmpi]){
                    flag = false;
                    break;
                }
                if(!flag){
                    break;
                }
            }
        }
        if(flag){
            ans++;
        }
        flag = true;
    }
    cout << n * ans << endl;

    return 0;
}