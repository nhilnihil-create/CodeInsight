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
    vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin >>s[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int cnt=0;
            if(s[i][j]=='.'){
                auto add=[&](int a,int b){
                    if(a<0||a>=h)return;
                    if(b<0||b>=w)return;
                    if(s[a][b]=='#')cnt++;
                };
                add(i,j+1);
                add(i,j-1);
                add(i+1,j+1);
                add(i+1,j-1);
                add(i-1,j+1);
                add(i-1,j-1);
                add(i+1,j);
                add(i-1,j);
                s[i][j]=(char)('0'+cnt);
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout <<s[i][j];
        }
        cout <<endl;
    }
    return 0;
}