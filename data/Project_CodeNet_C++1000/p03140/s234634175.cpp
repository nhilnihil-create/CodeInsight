#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    int ans=0;
    for(int i = 0; i < n; i++)
    {
        char a, b, c;
        a = s[0][i]; b = s[1][i]; c = s[2][i];
        if(a==b && c == a) continue;
        if(a!=b && b!=c && c!=a) ans+=2;
        else ans++;
    }
    cout << ans << endl;
    
    return 0;
}
