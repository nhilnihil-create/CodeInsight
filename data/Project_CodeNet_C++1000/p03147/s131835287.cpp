#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans=0;
 for(;;){
        int times=0;
        bool alzo=true;
        bool ze=false;
        rep(i,n){
            if(h[i]<=0 && ze==true){
                ze=false;
                continue;
            }
            if(ze==false && h[i]>0){
                times++;
                ze=true;
                alzo=false;
            }
            h[i]--;
        }
    if(alzo==true){
        cout << ans << endl;
        return 0;
    }
    ans+=times;
}
}
