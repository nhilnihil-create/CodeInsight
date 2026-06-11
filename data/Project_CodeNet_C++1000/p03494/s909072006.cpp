#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,c=0;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        c=0;
        while(a[i]%2!=1){
            a[i]/=2;
            c++;
        }
        a[i]=c;
    }
    sort(a,a+n);
    cout<<a[0]<<endl;
    return 0;
}
