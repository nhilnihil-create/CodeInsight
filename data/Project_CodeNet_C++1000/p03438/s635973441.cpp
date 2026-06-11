#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n],b[n],count=0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) count += b[i]-a[i];
    long long res=0;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]) res+=(b[i]-a[i]+1)/2;
    }
    if(res<=count) cout << "Yes" << endl;
    else cout << "No" << endl;
}