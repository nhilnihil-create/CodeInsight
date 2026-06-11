#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll h,w;cin>>h>>w;
    vector<vector<ll>>a(h,vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >>a[i][j];
        }
    }
    ll opt=0;
    vector<vector<ll>>ans(4,vector<ll>());
    for (int i =h-1; i >=0 ; --i) {
        for (int j = 0; j < w; ++j) {
            if(i-1<0)continue;
            if(a[i][j]%2==0)continue;
                a[i-1][j]++;
                a[i][j]--;
                opt++;
                ans[0].push_back(i);
                ans[1].push_back(j);
                ans[2].push_back(i-1);
                ans[3].push_back(j);
        }
    }
    for (int i = 0; i < w; ++i) {
        if(a[0][i]%2==0)continue;
        if(i+1>=w)continue;
        a[0][i+1]++;a[0][i]--;
        opt++;
        ans[0].push_back(0);
        ans[1].push_back(i);
        ans[2].push_back(0);
        ans[3].push_back(i+1);
    }
    cout <<opt<<endl;
    for (int i = 0; i < opt; ++i) {
        cout <<ans[0][i]+1<<" "<<ans[1][i]+1<<" "<<ans[2][i]+1<<" "<<ans[3][i]+1<<endl;
    }
    return 0;
}
