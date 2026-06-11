#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    string s;
    int min1 = 0, min2 = 0;
    int ans;
    cin >> s;

    rep(i, s.size()){
        if(s[i] == (char)('0' +(i % 2))) min1++;
        else if(s[i] == (char)('0' +((i+1) % 2))) min2++;
    }

    ans = min(min1, min2);
    cout << ans << endl;
    return 0;
}