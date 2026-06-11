#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    map<string,int> a;
    rep(i,n){
        string c;
        cin >> c;
        a[c]++;
    }
    int m;
    cin >> m;
    map<string,int> b;
    rep(i,m){
        string c;
        cin >> c;
        b[c]++;
    }
    int ans = 0;
    for(auto i:a){
        int cnt = a[i.first]-b[i.first];
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}