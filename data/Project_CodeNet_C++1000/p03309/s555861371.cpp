#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int hoge[n];
    long long ans=0;
    double b=0.0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        hoge[i] = a[i]-(i+1);
    }
    sort(hoge,hoge+n);
    if(n%2==1) b = hoge[(n-1)/2];
    else b = (hoge[n/2] + hoge[n/2-1])/2;
    for(int j=0;j<n;j++){
        ans += abs(a[j]-((j+1)+b));
    }
    cout<<ans<<endl;
    return 0;
}