#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    rep(i,3){
        if(s[i] == '1') {
            s[i] = '9';
            continue;
        }
        if(s[i] == '9') s[i] = '1';
    }
    cout << s << endl;
}