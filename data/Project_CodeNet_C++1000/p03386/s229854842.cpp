#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long int i=0;i<(n);i++)

int main(){
    long long int a,b,k;
    cin>>a>>b>>k;
    
    long long int c=b-a+1;
    
    if(c>=2*k){
        for(long long int i=0;i<k;i++){
            cout<<a+i<<endl;
        }
        for(long long int i=k-1;i>=0;i--){
            cout<<b-i<<endl;
        }
    }
            
    else rep(i,c)cout<<a+i<<endl;
    
}