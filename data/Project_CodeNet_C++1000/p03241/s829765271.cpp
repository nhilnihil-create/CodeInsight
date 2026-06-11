#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m;cin>>n>>m;
    int mx=0;
    for (int i=1;i*i<=m;i++)
        if (m%i==0) {
            int j=m/i;
            if (n<=i) {
                cout<<j<<endl;
                return 0;
            }
            if (n<=j)
                mx=i;
        }
    cout<<mx<<endl;
    return 0;
}