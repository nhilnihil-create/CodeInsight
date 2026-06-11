#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>t(n+1);
    vector<int>x(n+1);
    vector<int>y(n+1);
    for(int i=1;i<=n;i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    t[0]=0;
    x[0]=0;
    y[0]=0;
    bool judge=true;
    for(int i=1;i<=n;i++){
        int time=t[i]-t[i-1];
        int dx=abs(x[i]-x[i-1]);
        int dy=abs(y[i]-y[i-1]);
        if(time<(dx+dy)||time%2!=(dx+dy)%2){
            judge =false;
        }
    }
    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}