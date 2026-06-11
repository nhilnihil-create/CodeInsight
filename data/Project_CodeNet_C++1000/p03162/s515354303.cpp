#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);

    for(int i= 0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    vector<int> dpA(n), dpB(n), dpC(n);         /// dpA[i] = A was done in i-th day

    dpA[0] = a[0];
    dpB[0] = b[0];
    dpC[0] = c[0];

    for(int i = 1; i<n; i++){
        dpA[i] = a[i] + max(dpB[i-1], dpC[i-1]);
        dpB[i] = b[i] + max(dpA[i-1], dpC[i-1]);
        dpC[i] = c[i] + max(dpA[i-1], dpB[i-1]);
    }


    int ans = max({dpA[n-1], dpB[n-1], dpC[n-1]});

    cout<<ans<<endl;


    return 0;
}
