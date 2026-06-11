#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    string T;
    bool flag;
    count=0;
    ans=0;
    flag=false;
    cin >>N>>H>>ans;
    
    
        for (i=0;i<10;i++){
            ans=N*ans-H;
            cout <<ans<<endl;
        }

    
    

    return 0;
    
}
