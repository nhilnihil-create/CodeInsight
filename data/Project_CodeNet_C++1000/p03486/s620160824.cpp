#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {

    string  s,t,w; cin >> s >> t;
    w = t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    rep(i,t.length()){
        w[i] = t[t.length()-1-i];
    }


    if(s < w) cout << "Yes";
    else cout << "No";

    return 0;
}









