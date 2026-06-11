#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());

    int ans = n;// MAX
    int count = 1;
    for(int i=0; i<n; i++){
        if(i == n-1 || p[i].second > p[i+1].second){
            ans = min(ans, n - count);
            count = 1;
        }
        else count += 1;
    }
    cout << ans << endl;
    return 0;
}