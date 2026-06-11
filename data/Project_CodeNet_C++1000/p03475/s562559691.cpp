#include<bits/stdc++.h>
using namespace std;
long long int ans[505];
int main(){
    int n;
    cin >> n;
    long long int c[n],s[n],f[n];
    for(int i=0;i<n-1;i++){
        cin >> c[i] >> s[i] >> f[i];
        for(int j=0;j<=i;j++)ans[j] = max(((ans[j]+f[i]-1)/f[i])*f[i],s[i])+c[i];
    }
    for(int i=0;i<n;i++)cout << ans[i] << endl;
}