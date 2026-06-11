#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main(){
    string s;
    cin >> s;

    
    int ans = 1000;

    for(int i=0;i<s.length()-2;i++){
        int tem = 0;
        tem = s[i+2]-'0' + 10*(s[i+1]-'0') + 100*(s[i]-'0');
        ans = min(abs(tem-753),ans);
    }

    cout << ans << endl;


    return 0;

}
