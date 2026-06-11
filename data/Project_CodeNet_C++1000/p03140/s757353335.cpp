#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string a,b,c; cin>>a>>b>>c;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(a[i]==b[i]){
            if(b[i]==c[i]) ans +=0;
            else ans += 1;
        }
        else if(b[i]==c[i]) ans +=1;
        else if(a[i]==c[i]) ans +=1;
        else ans += 2;
    }
    cout << ans << endl;
    return 0;
}