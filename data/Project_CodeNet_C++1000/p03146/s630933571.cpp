#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
    cin >> a[0];
    int ans;
    for(int i=1;i<1e6+1;i++){
        if(a[i-1]%2==0)a[i]=a[i-1]/2;
        else a[i]=3*a[i-1]+1;
        if(b[a[i]]>0||a[i]==a[0]){
            ans=i; break;
        }
        b[a[i]]=i;
    }
    cout << ans+1 << endl;
}