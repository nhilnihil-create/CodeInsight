#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long long int r=0;
    long long int p=a[0]; long long int x=a[0];
    long long int ans=0;
    for(long long int l=0;l<n;l++){
        while(p==x && r<n){
            r++;
            if(r<n){
                p+=a[r]; x^=a[r];
            }
        }
        ans+=(r-l);
        p-=a[l]; x^=a[l];
    }
    cout << ans;
}