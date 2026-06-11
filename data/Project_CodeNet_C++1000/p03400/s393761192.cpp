#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,d,x;
    cin>>n>>d>>x;
    int ans=x+n,D=d-1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans+=D/a;
    }
    cout<<ans<<endl;
    return 0;
}