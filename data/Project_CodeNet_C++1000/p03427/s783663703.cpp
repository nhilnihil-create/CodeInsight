#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009

int main(){
    string a;
    cin >> a;
    ll ans = 0;
    bool flag = true;
    for(int i = a.size()-1;i >= 0;i--){
        if(i != 0){
            ans += 9;
            if(a[i] != '9') flag = false;
        }
        else{
            if(flag) ans += a[i] - '0';
            else ans += a[i] - '0' - 1;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}