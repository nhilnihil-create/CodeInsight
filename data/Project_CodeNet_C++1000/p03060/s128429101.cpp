#include <iostream>
using namespace std;
int main()
{
    int a=0,n,v[50],c[50],d[25];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        d[i]=v[i]-c[i];
    }
    
    
    for(int i=0;i<n;i++){
        
        if(d[i]>=0){
            a=d[i]+a;
        }
        
        
    }
    std::cout << a << std::endl;
}