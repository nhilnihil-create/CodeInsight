#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[101],n,AS=0,BS=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i-=2){
        AS+=a[i];
    }
    for(int j=n-2;j>=0;j-=2){
        BS+=a[j];
    }
    cout<<AS-BS;

    return 0;
}
