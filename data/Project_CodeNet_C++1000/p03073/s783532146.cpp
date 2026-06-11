#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main(){
    string S; 
    cin>>S;
    int cnt=0,ans=0;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) {
            if (S.at(i) != '0') cnt++;
        } else {
            if (S.at(i) != '1') cnt++;
        }
    }
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) {
            if (S.at(i) != '1') ans++;
        } else {
            if (S.at(i) != '0') ans++;
        }
    }
    ans = min(ans, cnt);
    cout << ans << endl;
}
