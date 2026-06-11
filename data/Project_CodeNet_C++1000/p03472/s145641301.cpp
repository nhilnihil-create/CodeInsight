#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,h;
    cin >> n >> h;
    vector<pair<int,bool>> ab(2*n);
    for(int i = 0; i < n; i++) {
        cin >> ab[i*2].first >> ab[i*2+1].first;
        ab[i*2].second=false;
        ab[i*2+1].second=true;
    }
    sort(ab.rbegin(),ab.rend());

    int cnt=0;
    ll dmg=0;
    while(ab[cnt].second){
        dmg+=ab[cnt].first;
        cnt++;
        if(dmg>=h){
            cout << cnt << "\n";
            return 0;
        }
    }
    ll ta=ab[cnt].first;
    cnt += ((h-dmg+ta-1)/ta);
    cout << cnt << "\n";

    return 0;
}