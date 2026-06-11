#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n,y;cin>>n>>y;
    y /= 1000;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n-i;j++) {
            int x = (i*10) + (j*5) + (n-i-j);
            if(x == y) {
                cout<<i<<" "<<j<<" "<<n-i-j<<"\n";
                return 0;
            }
        }
    }
    cout <<"-1 -1 -1\n";
    return 0;
}