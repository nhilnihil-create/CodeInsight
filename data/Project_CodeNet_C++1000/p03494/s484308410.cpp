#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%2==1){
            break;
        }else{
            a[i]/=2;
        }
        if(i==n-1){
            ans++;
            i=0;
        }
    }
    cout << ans << endl;
    return 0;
}