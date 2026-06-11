#include <bits/stdc++.h>
using namespace std;


bool primeNumber(long long n){
    if(n < 2) return false;
    else{
        for(long long j = 2; j* j <= n; j++){
            if(n % j == 0) return false;
        }
        return true;
    }
}


int main() {
long long Q;
cin>>Q;
long long A[100010]={};
A[0]=0;
A[1]=0;
A[2]=0;
for(long long i=2; i<=100000; i++){
    if(i%2!=0){
        if(primeNumber(i)==true && primeNumber(((i+1)/2))==true){
            A[i+1]=A[i-1]+1;
        }
        else{
            A[i+1]=A[i-1];
        }
        
    }
}
    
 for(long long i=0; i<Q; i++){
     long long l,r;
     cin>>l>>r;
     cout<<A[r+1]-A[l-1]<<endl;
 }   
    


}