#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n,t,a;
    cin >> n >> t >> a;

    double ans,min(100000);
    rep(i,n){
        double h;  cin >> h;

        h = t - (h*0.006);
        if(min>abs(a-h)){
            min = abs(a-h);
            ans = i;
        }
    }

    cout << ans+1 << endl;

    return 0;
}