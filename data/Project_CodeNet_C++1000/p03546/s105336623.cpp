#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int h,w;cin >>h>>w;
    vector<vector<int>>d(10,vector<int>(10));
    for (int i = 0; i <10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >>d[i][j];
        }
    }
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans=0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int a;cin >>a;
            if(a!=-1) {
                ans += d[a][1];
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}