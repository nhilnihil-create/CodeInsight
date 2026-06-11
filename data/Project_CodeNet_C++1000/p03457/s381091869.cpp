#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> t(n+1),x(n+1),y(n+1);
    t[0]=0;
    x[0]=0;
    y[0]=0;

    for(int i = 0; i < n; i++) {
        int p,q,r;cin >> p >> q >> r;
        t[i+1]=p;
        x[i+1]=q;
        y[i+1]=r;
    }

    for(int i = 0; i < n; i++) {
        int td=t[i+1]-t[i];
        int d=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);

        if(td>=d && (td-d)%2==0) continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}