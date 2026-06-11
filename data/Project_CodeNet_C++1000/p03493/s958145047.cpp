#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,count=0;
    cin>>n;
    while(n!=0)
    {
        if(n%10==1)
        count++;
        n=n/10;
    }
    cout<<count<<endl;
}