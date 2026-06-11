#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long int V[200010];
long long int C[200010];




int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    
    
    string T;
    bool flag;
    count=0;
    ans=0;
    flag=false;
    cin >>N;
    
    
    for (i=0;i<N;i++){
        cin>>V[i];
    } 
    for (i=0;i<N;i++){
        cin>>C[i];
        if (V[i]-C[i]>0){
            ans+=V[i]-C[i];
        }
    } 
    
    
    
    
    cout<< ans <<endl;
    

    return 0;
    
}

