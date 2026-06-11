#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long n;
    unsigned long long cnt=0;
    cin>>n;
    /*if(n==2) {
        cout<<0<<endl;
        return 0;
    }*/
    for(long long i = 1 ; i<sqrt(n);i++){
        if(n%i==0){
           // cout<<" =i "<<endl;
           long long dd = n/i;
           if(i<dd-1){
                cnt += (n/i)-1;
           }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
