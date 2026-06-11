#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    map<string,double> m;
    for(int i=0;i<n;i++){
        double x;
        string u;
        cin >> x >> u;
        m[u] += x;
    }
    cout << fixed << setprecision(4) << m["BTC"] *380000.0 + m["JPY"] << endl;
}