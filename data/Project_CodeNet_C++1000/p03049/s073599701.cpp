#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int cnt=0;
    int a=0;
    int b=0;
    int c=0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int l=s.size();
        for(int i = 1; i < l; i++) if(s[i-1]=='A'&&s[i]=='B') cnt++;
        if(s[0]=='B') b++;
        if(s[l-1]=='A') a++;
        if(s[0]=='B' && s[l-1]=='A') c++;
    }
    a-=c;
    b-=c;
    if(c>1){
        cnt+=c-1;
        c=1;
    }
    if(c==1){
        if(a>0){
            a--;
            cnt++;
        }
        if(b>0){
            b--;
            cnt++;
        }
    }
    cnt+=min(a,b);
    cout << cnt << "\n";
    return 0;
}