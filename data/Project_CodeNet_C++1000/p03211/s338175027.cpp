#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    string s; cin >> s;
    int sl=s.length();
    int ans=INF;
    rep(i,sl-2){
        int a=(s[i]-'0')*100;
        int b=(s[i+1]-'0')*10;
        int c=(s[i+2]-'0');
        ans=min(ans,abs(a+b+c-753));
    }
    cout << ans << endl;
    return 0;
}
