#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100001],Min=10000000000;
int r;
int main() {
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(Min>abs(a[n-1]/2.0-a[i])){
            Min=abs(a[n-1]/2.0-a[i]);
            r=i;
        }
    }
    cout<<a[n-1]<<" "<<a[r]<<endl;
}
