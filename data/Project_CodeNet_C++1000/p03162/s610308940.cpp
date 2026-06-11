#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[100100],b[100100],c[100100];
int dp_a[100100],dp_b[100100],dp_c[100100];

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    dp_a[0]=0;
    dp_b[0]=0;
    dp_c[0]=0;

    for(int i=1;i<=n;i++){
        dp_a[i]=max(b[i-1]+dp_b[i-1],c[i-1]+dp_c[i-1]);
        dp_b[i]=max(a[i-1]+dp_a[i-1],c[i-1]+dp_c[i-1]);
        dp_c[i]=max(a[i-1]+dp_a[i-1],b[i-1]+dp_b[i-1]); 
    }
    /*
    cout<<dp_a[n]<<" ";
    cout<<dp_b[n]<<" ";
    cout<<dp_c[n];

    cout<<endl;
    */
    int dpa =dp_a[n-1]+a[n-1];
    int dpb =dp_b[n-1]+b[n-1];
    int dpc =dp_c[n-1]+c[n-1];
    /*
    cout<<dpa<<" ";
    cout<<dpb<<" ";
    cout<<dpc;
    */
    int maiorPath=max(dpa,dpb);
    maiorPath=max(maiorPath,dpc);
    cout<<maiorPath;

}
