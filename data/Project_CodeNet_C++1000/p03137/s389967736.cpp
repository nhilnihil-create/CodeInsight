#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> x(m);
    for (int i = 0; i < m; i++) cin >> x[i];
    
    
    if (m <= n){
        cout << 0 << endl;
        return 0;
    }
    
    sort(x.begin(),x.end());
    
    vector<int> interval(m);
    for (int i = 0; i < m-1; i++){
        interval[i] = x[i+1] - x[i];
    }
    
    sort(interval.rbegin(),interval.rend());
    
    int ans = x[m-1] - x[0];
    
    for (int i = 0; i < n-1; i++){
        ans -= interval[i];
    }
    cout << ans << endl;
}