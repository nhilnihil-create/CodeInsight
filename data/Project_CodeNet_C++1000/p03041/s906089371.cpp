
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    if(s[k-1]=='A') s[k-1]='a';
    else if(s[k-1]=='B') s[k-1]='b';
    else s[k-1]='c';

    cout << s << endl;
}