#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    int ans = 20000,count,c,d;
    for(int i=0; i<n; i++){
       cin >> c >> d;
       if(d<=t){
         ans=min(ans,c);
       }
    }
    if(ans==20000) cout << "TLE" << endl;
    else cout << ans << endl;
    return 0;   
}