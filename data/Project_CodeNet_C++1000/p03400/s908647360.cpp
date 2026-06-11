#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n,d,x;
    cin >> n;
    cin >> d >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = x;
    for(int i=0;i<n;i++){
        int j = 0;
        while(1+a[i]*j <= d){
            ans++;
            j++;
        }
    }
    cout << ans << endl;

}