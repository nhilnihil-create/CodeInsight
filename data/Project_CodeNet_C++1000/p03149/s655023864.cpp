#include <bits/stdc++.h>
using namespace std;
int main() {
    bool ok[10]={0};
    int a[4],i;
    for (i=0;i<4;i++) {
        cin >>a[i];
        ok[a[i]]=1;
    }
    if (ok[1]==1 && ok[9]==1 && ok[7]==1 && ok[4]==1) cout <<"YES";
    else cout <<"NO";
    return 0;
}