#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,a[10],i,sum=0;
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    a[n-1] = a[n-1]/2;
    for(i=0;i<n;i++) sum+=a[i];
    cout << sum;
}