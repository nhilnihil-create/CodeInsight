#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    string s;
    int k;
    cin >> s >> k;
    char ans = '1';
    int cnt = 0;
    rep(i,s.size()){
        if (s[i] != '1'){ans = s[i];break;}
        else cnt++;
    }
    if (k <= cnt)cout << '1';
    else cout << ans;
}