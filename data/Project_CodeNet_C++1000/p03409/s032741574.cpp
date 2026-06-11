#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    P  redy[n], bluex[n];
    rep(i, n) cin >> redy[i].second >> redy[i].first;
    rep(i, n) cin >> bluex[i].first >> bluex[i].second;
    sort(redy, redy+n);
    sort(bluex, bluex+n);

    int ans = 0;
    int ri = 0, bi = 0;
    bool usedr[n] = {0};
    rep(bi, n){
        vector<int> rcand;
        rep(ri, n){
            if(!usedr[ri] && redy[ri].second < bluex[bi].first && redy[ri].first < bluex[bi].second){
                rcand.push_back(ri);
            }
        }
        if(rcand.size()){
            sort(all(rcand), [&](const int a, const int b){
                return redy[a] > redy[b];
            });
            usedr[rcand[0]] = true;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}