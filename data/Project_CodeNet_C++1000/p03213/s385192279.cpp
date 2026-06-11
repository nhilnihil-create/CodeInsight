#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int pf[100]{};
    int c[1000]{};
    for (int i=2;i<=n;i++) {
        int t=i;
        for (int j=2;j*j<=t&&t>1;j++)
            while (t%j==0) {
                t/=j;
                pf[j]++;
                c[pf[j]]++;
            }
        if (t>1) {
            pf[t]++;
            c[pf[t]]++;
        }
    }
    cout<<c[74]+c[24]*(c[2]-1)+c[14]*(c[4]-1)+c[4]*(c[4]-1)/2*(c[2]-2)<<endl;
    return 0;
}