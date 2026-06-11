/**
*    author:  souzai32
*    created: 04.08.2020 01:42:29
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin>> b.at(i);

    vector<int> c;
    long long point=0;
    int ans=0;
    rep(i,n){
        if(b.at(i)>a.at(i)){
            point+=b.at(i)-a.at(i);
            ans++;
        }
        else c.push_back(a.at(i)-b.at(i));
    }
    sort(c.begin(),c.end(),greater<>());
    //cout << point << endl;
    //cout << ans << endl;

    if(point>0){
        for(int i=0; i<c.size(); i++){
            point-=c.at(i);
            ans++;
            if(point<=0) break;
        }
    }
    

    if(point<=0) cout << ans << endl;
    else cout << -1 << endl;

    //cout << endl;
    //rep(i,c.size()) cout << c.at(i) << endl;

    return 0;
}