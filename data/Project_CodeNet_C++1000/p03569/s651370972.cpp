#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    string s;
    cin >> s;
    string t,u;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]!='x') t += s[i];
    }
    u=t;
    reverse(u.begin(),u.end());
    if(t != u){
        cout << -1 << endl;
        return 0;
    }

    vector<int> a;
    int d=0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='x') d++;
        else{
            a.push_back(d);
            d=0;
        }
    }

    a.push_back(d);


    ll ans=0;

    for(int i = 0; i < (a.size()+1)/2; i++) {
        ans += abs(a[i]-a[t.size()-i]);
    }

    cout << ans << endl;

    return 0;
}