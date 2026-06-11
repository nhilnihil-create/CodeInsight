#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int x; cin >> x;
    int ans = 1;
    for(int b = 2; b <= x; ++b){
        int tmp = b*b;
        while(tmp <= x){
            ans = max(ans, tmp);
            tmp *= b;
        }
    }
    cout << ans << endl;
}