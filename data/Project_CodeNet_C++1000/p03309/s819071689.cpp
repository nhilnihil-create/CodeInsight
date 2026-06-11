#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int  main(){
    long long int  n;
    cin>>n;
    vector<long long int >v(n);
    for(long long int  i=0;i<n;i++){
        cin>>v[i];
    }
    long long int  result=0;
    for(long long int  i=0;i<n;i++)
    {
        v[i]=v[i]-i-1;
    }
    sort(v.begin(),v.end());
    long long int f=v[n/2];
    if(n%2==0){
        f=(v[n/2]+v[n/2-1])/2;
    }
    long long int finalresult=0;
    for(long long int  i=0;i<n;i++)
    {
        finalresult+=abs(v[i]-f);
    }
    cout<<finalresult;
}