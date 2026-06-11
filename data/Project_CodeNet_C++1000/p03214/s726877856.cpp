#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        a[i] *= n;
    }
    int diff = 1e7;// INF
    int ans = 0;
    for(int i=0; i<n; i++){
        if(abs(a[i] - sum) < diff){
            ans = i;
            diff = abs(a[i] - sum);
        }
    }
    cout << ans << endl;
    return 0;
}