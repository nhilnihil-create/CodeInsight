#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int d[n+1];
    d[0]=0;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        d[a]=i;
    }

    int c[n+1];
    fill(c, c+n+1, 0);
    for(int i=1; i<=n; i++){
        if(d[i]>d[i-1]) c[i]=c[i-1]+1;
        else c[i]=1;
    }
    int ans=n;
    for(int i=1; i<=n; i++){
        ans=min(ans, n-c[i]);
    }
    cout << ans << endl;
    return 0;
}