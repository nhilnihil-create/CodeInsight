#include<bits/stdc++.h>

using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    long long l,r;
    long long arr[n+1]={0};
    for(long long int i=0;i<m;i++)
    {
        cin>>l>>r;
        l--;
        arr[l]++;
        arr[r]--;
    }
    for(long long int i=1;i<n+1;i++){
        arr[i]+=arr[i-1];
    } 
    long long count=0;
    for(long long i=0;i<n+1;i++){ 
        if(arr[i]==m){
            count++;
        }
    } 
    cout<<count;
}