#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);  
    int n;  
    string a,b,c;
    cin >> n >> a >> b >> c;
    int cnt= 0;
    REP(i,n){
        cnt+= ((a[i]==b[i] && a[i]!=c[i]|| a[i]==c[i] && a[i]!=b[i]|| b[i]==c[i]&& b[i]!=a[i])?1:((a[i]==b[i] && b[i]==c[i])?0:2));
    }
    cout << cnt << endl;
}