#include <bits/stdc++.h>
using namespace std;
int m,k;
int main() {
    cin>>m>>k;
    if (m>=2) {
        if (k<=(1<<m)-1) {
            for (int i=(1<<m)-1; i>=0; i--) {
                if (i!=k) cout<<i<<' ';
            }
            cout<<k<<' ';
            for (int i=0; i<=(1<<m)-1; i++) {
                if (i!=k) cout<<i<<' ';
            }
            cout<<k<<'\n';
        }
        else cout<<"-1\n";
    }
    else if (m==1) {
        if (k>=1) cout<<"-1\n";
        else cout<<"1 0 0 1\n";
    }
    else {
        if (k>=1) cout<<"-1\n";
        else cout<<"0 0\n";
    }
}