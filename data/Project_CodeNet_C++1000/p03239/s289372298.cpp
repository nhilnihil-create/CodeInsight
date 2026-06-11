#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N,T;
    cin >> N >> T;
    vector<int> c(N),t(N);
    vector<pair<int,int>> p(N);
    for(int i = 0; i < N; i++){
        cin >> c[i] >> t[i];
        p[i] = make_pair(t[i],c[i]);
    }
    sort(p.begin(),p.end());
    //reverse(p.begin(),p.end());
    int ans = 10000;
    for(int i = 0; i < N; i++){
        if(p[i].first <= T){
            ans = min(ans,p[i].second);
        }
    }
    if(ans == 10000) cout << "TLE" << endl;
    else cout << ans << endl;
}
