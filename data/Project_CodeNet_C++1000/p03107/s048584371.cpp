#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    int cnt_0=0,cnt_1=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cnt_0++;
        }
        else{
            cnt_1++;
        }
    }
    int ans=min(cnt_0,cnt_1);
    ans*=2;
    cout << ans << endl;
}
