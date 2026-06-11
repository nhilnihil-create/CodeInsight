#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int v1=0,v2=0;
    rep(i,s.size()){
        if(s[i]=='0')v1++;
        if(s[i]=='1')v2++;
    }

    cout << min(v1,v2)*2;
    return 0;
}