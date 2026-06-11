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
    int n;cin >>n;
    vector<P>red(n);
    vector<P>blue(n);
    for (int i = 0; i < n; ++i) {
        int a,b;cin >>a>>b;
        red[i]={a,b};
    }
    for (int i = 0; i < n; ++i) {
        int c,d;cin >>c>>d;
        blue[i]={c,d};
    }
    sort(all(red));
    sort(all(blue));
    int k=0;
    int ans=0;
    vector<bool>ch(n,true);
    for (int i = 0; i < n; ++i) {
        vector<P>que;
        for (int j = 0; j <n; ++j) {
            if(red[j].first<blue[i].first&&red[j].second<blue[i].second){
                if(ch[j]){
                    que.push_back({red[j].second,j});
                }
            }
        }
        if(!que.empty()) {
            sort(all(que));
//            cout <<que.back().first<<" "<<blue[i].first<<" "<<blue[i].second<<endl;
            ch[que.back().second]=false;
            ans++;
        }
    }
    cout <<ans <<endl;
    return 0;
}