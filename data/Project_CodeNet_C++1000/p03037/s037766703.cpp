#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector <int> l(m);
    vector <int> r(m);
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int ans = 1;
    ans += r[0]-l.back();
    if(ans<0)ans=0;
    cout << ans << endl;
    return 0;
}