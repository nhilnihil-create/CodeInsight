#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int k;
    vector<int> a;
    cin >> k;
    a.assign(k+1, 1);
    for(int i=1;i<=k;i++){
        cin >> a[i];
    }
    if(a[k] != 2){
        cout << -1 << endl;
        return 0;
    }

    long long mn = 2, mx = 2;
    for(int i=k;i>=1;i--){
        long long dlt = (a[i-1] - mn%a[i-1]) % a[i-1];
        mn += dlt;
        mx = (mx + a[i]-1) / a[i-1] * a[i-1];
        if(mx < mn){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << mn << " " << mx << endl;
}
