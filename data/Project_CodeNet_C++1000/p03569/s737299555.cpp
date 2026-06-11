#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;

int main(void){
    cin >> s;
    lli l, r;
    l = 0, r = s.size()-1;
    lli ans = 0;
    while(r-l > 0){
        if(s[l] == s[r]) l++, r--;
        else if(s[l] == 'x') ans++, l++;
        else if(s[r] == 'x') ans++, r--;
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
