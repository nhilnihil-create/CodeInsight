#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,T,c;
    cin>>n>>T;
    int a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>c>>t;
        if(t<=T){
            a[i]=c;
            b[i]=t;
    }
    else
    {
      a[i]=1002;
      b[i]=1002;
    }
    }
    sort(a, a+n);
    if(a[0]==1002)
        cout<<"TLE"<<endl;
    else
    cout<<a[0]<<endl;
}