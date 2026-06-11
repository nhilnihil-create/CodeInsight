#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int>a(n);
    vector<int>b(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int ans=0, w;

    for(int i=0; i<n; i++){
        w = 0;
        for(int t=0; t<=i; t++){
            w += a[t];
        }
        for(int s=n-1; s >= i; s--){
            w += b[s];
        }
        ans = max(ans, w);
    }

    cout << ans << endl;

    return 0;
}