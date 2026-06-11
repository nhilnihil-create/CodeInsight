#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int sum_a=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum_a += a[i];
    }
    int ans = sum_a - n;
    cout << ans << endl;
    return 0;
}