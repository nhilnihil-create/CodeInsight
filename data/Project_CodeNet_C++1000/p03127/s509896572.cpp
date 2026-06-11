#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b == 0 ? a : gcd(b, a % b);}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = a[0];
    for(int i = 1; i < n; i++)
        ans = gcd(ans, a[i]);
    cout << ans << endl;
    return 0;
}