#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    vector<int> a(9);
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    bool w=false,x=false;
    if(a[1]-a[0]==a[4]-a[3] && a[4]-a[3]==a[7]-a[6]) w=true;
    if(a[1]-a[2]==a[4]-a[5] && a[4]-a[5]==a[7]-a[8]) x=true;

    if(w && x) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}