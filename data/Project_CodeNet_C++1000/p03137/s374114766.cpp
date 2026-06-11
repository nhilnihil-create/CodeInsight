#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>a(m);
    for(int i=0; i<m; i++){
        cin >> a[i];
    }

    if(n>=m){
        cout << 0 << endl;
        return 0;
    }
    
    sort(a.begin(),a.end());

    vector<int>sa(m-1);
    for(int i=0; i<m-1; i++){
        sa[i] = abs(a[i+1]-a[i]);
    }

    sort(sa.begin(),sa.end());
    int ans=0;
    for(int i=0; i<m-n; i++){
        ans += sa[i];
    }
    cout << ans << endl;
    return 0;
}