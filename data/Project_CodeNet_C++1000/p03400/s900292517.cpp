#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d,x;
    cin >> n >> d >> x;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long ans = x;
    for(int i = 0; i < n; i++){
        for(int j = 0; ((j*a[i]+1)<=d); j++){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}