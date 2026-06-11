#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    int p[n];
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p,p+n);
    int ans[3];
    for(int i=0;i<3;i++) ans[i]=0;
    for(int i=0;i<n;i++){
        if(p[i]<=a) ans[0]++;
        else if(p[i]>=a+1&&p[i]<=b) ans[1]++;
        else if(p[i]>=b+1) ans[2]++;
    }
    cout << min(ans[0],min(ans[1],ans[2])) << endl;
}