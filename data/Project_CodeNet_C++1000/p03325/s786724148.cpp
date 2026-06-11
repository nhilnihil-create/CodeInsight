#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int tmp=0;
    int ans=0;
    while(tmp<n){
        if(a[tmp]%2==0){
            a[tmp]/=2;
            ans++;
        }
        else tmp++;
    }
    cout << ans << endl;
}