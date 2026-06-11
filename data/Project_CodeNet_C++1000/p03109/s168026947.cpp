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
    int month = (s[5] - '0') * 10 + (s[6] - '0');
    if(month >= 5) cout << "TBD" << endl;
    else cout << "Heisei" << endl;
}