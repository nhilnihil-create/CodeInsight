#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int K;
    int N;
    cin>>N;
    cin>>K;
    string bruh;
    cin>>bruh;
    for(int i=0;i<N;i++){
        if(i==K-1){
           bruh[i]+=( char)32; 
         
        }
       
    }
    cout<<bruh<<endl;
   
    return 0;
}
