#include<bits/stdc++.h>
using namespace std;


#define ll long long int
int main()
{


    int n;
    cin>>n;
int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll sum=0,mx=a[0];

    for(int i=1;i<n;i++){
      if(a[i]>=a[i-1]) mx+=a[i]-a[i-1];
    }
    cout<<mx<<endl;


}
