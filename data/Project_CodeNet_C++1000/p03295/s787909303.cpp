#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    pair<int,int> p[m];
    for(int i = 0; i < m; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p,p+m);
    int MAX=0;
    int ans=0;
    for(int i=0;i<m;i++){
        if(p[i].second>MAX){
            ans++;
            MAX=p[i].first-1;
        }
    }
    cout << ans << endl;
}
