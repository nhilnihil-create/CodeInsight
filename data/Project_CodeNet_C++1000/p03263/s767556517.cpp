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
    int h,w;cin>>h>>w;
    vector<vector<int>>a(h,vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >>a[i][j];
        }
    }
    vector<int>ans0;
    vector<int>ans1;
    vector<int>ans2;
    vector<int>ans3;
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h - 1; ++i) {
            if(a[i][j]%2==1){
                a[i+1][j]++;
                a[i][j]--;
                ans0.push_back(i+1);
                ans1.push_back(j+1);
                ans2.push_back(i+2);
                ans3.push_back(j+1);
            }
        }
    }
    for (int j = 0; j < w - 1; ++j) {
        if(a[h-1][j]%2==1){
            a[h-1][j+1]++;
            a[h-1][j]--;
            ans0.push_back(h);
            ans1.push_back(j+1);
            ans2.push_back(h);
            ans3.push_back(j+2);
        }
    }
    cout <<ans0.size()<<endl;
    for (int i = 0; i < ans0.size(); ++i) {
        cout <<ans0[i]<<" "<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<endl;
    }
    return 0;
}
