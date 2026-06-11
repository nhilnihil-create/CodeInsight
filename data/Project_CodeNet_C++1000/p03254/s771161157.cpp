#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    int mx=0;
    for(int i=0; i<n; i++){
        mx += a[i];
        if(x >= mx){
            ans++;
        }else{
            break;
        }
    }
    if(ans == n && x != mx) ans--;
    cout << ans << endl;
}


