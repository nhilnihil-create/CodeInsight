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

int n;
int ans;


ll ni(ll a,ll b){
    if(b==0) return 1;
    else if(b%2==0) return ni(a,b/2)*ni(a,b/2);
    else return ni(a,b-1)*a;
}

void solve(string s,int kurai){
    ll now=0;
    int sl=s.length();
    bool c3,c5,c7;
    c3=c5=c7=false;
    rep(i,sl){
        int keta=s[i]-'0';
        now+=keta*ni(10,sl-i-1);
        if(keta==3) c3=true;
        if(keta==5) c5=true;
        if(keta==7) c7=true;
    }
    //cout << now << endl;
    if(now>n) return;
    if(c3 && c5 && c7) ans++;
    s[kurai]='3';
    solve(s,kurai-1);
    s[kurai]='5';
    solve(s,kurai-1);
    s[kurai]='7';
    solve(s,kurai-1);
}

int main(){
    cin >> n;
    solve("0000000000",9);
    cout << ans << endl;
    return 0;
}
