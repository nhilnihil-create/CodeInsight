#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long double a;
    cin>>n;
    long double sum=0;
    long double A[n];
    for (int i=0;i<n;i++) {
        cin>>a;
        A[i]=a;
        sum+=a;
    }
    long double ave=sum/n;
    int ans=0;
    long double Minabs=100000;
    for (int i=0;i<n;i++) {
        if (Minabs>abs(A[i]-ave)) {
            Minabs=abs(A[i]-ave);
            ans=i;
        }
    }
    cout<<ans<<endl;
}