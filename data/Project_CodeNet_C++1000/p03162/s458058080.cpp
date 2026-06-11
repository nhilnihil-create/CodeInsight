#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, a[100100], b[100100], c[100100], happy[100100][3]={0}, i, pre=-1;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    happy[0][0]=a[0];
    happy[0][1]=b[0];
    happy[0][2]=c[0];    
    for(i=1;i<n;i++){
       happy[i][0]=max(happy[i-1][1]+a[i], happy[i-1][2]+a[i]);
       happy[i][1]=max(happy[i-1][0]+b[i], happy[i-1][2]+b[i]);
       happy[i][2]=max(happy[i-1][0]+c[i], happy[i-1][1]+c[i]);
    }

    cout << max({happy[n-1][0], happy[n-1][1], happy[n-1][2]}) <<endl;
    return 0;
}
