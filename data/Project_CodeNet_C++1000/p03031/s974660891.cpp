#include <bits/stdc++.h>
using namespace std;
int n,m,k[101],p1,p[101],ans;
vector<int> arr[101];
int main() {
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        cin>>k[i];
        for (int j=0; j<k[i]; j++) {cin>>p1; arr[i].push_back(p1-1);}
    }
    for (int i=0; i<m; i++) cin>>p[i];
    for (int i=0; i<(1<<n); i++) {
        int imp=0;
        for (int j=0; j<m; j++) {
            int on=p[j];
            for (int l=0; l<k[j]; l++) {
                if (i&(1<<arr[j][l])) on++;
            }
            if ((on%2)==1) {imp=1; break;}
        }
        if (!imp) ans++;
    }
    cout<<ans<<'\n';
}