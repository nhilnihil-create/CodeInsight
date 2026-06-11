#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    int ans = 0;
    int a = 0,b = 0,k = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < s[i].size()-1; j++){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }
        if(s[i][s[i].size()-1] == 'A') a++;
        if(s[i][0] == 'B') b++;
        if(s[i][s[i].size()-1] == 'A' && s[i][0] == 'B') k++;
    }    
    if(a == b && b == k && k != 0) ans--;
    ans += min(a,b);
    cout << ans << endl;
}