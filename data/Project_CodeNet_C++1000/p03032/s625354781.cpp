#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n){
        cin >> v.at(i);
    }

    vector<int> fr(n+1),fl(n+1);
    fl.at(0) = 0;
    fr.at(0) = 0;
    rep(i,n){
        fl.at(i+1) = fl.at(i) + v.at(i);
        fr.at(i+1) = fr.at(i) + v.at(n-1-i);
    }
    // rep(i,n+1) cout << fl.at(i) << " ";
    // cout << endl;
    // rep(i,n+1) cout << fr.at(i) << " ";
    // cout << endl;

    vector<pair<int,int>> vp;
    rep(i,n){
        if(v.at(i) < 0) vp.push_back({v.at(i), i});
    }
    sort(vp.begin(), vp.end());

    int res = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n && i+j<=k && i+j<=n;j++){
            int kmx = k-i-j;
            int kcr=0;
            int tot=0;
            tot += fl.at(i);
            tot += fr.at(j);
            for(auto p:vp){
                if(kcr>=kmx) break;
                if(p.second < i || p.second > n-1-j){
                    kcr++;
                    tot -= p.first;
                }
            }
            // if(res <= tot){
            //     cout << i << " " << j << " " << tot << endl;
            // }
            res = max(res,tot);
        }
    }
    cout << res << endl;
    return 0;
}