#include <iostream>
using namespace std;

int main(){
    int n,a[4];
    
    cin>>n;
    
    for(int i=0;i<4;i++){
        a[i]=n%10;
        n/=10;
    }
    
    if(a[0]==a[1]&&a[1]==a[2])
        cout<<"Yes"<<endl;
    else if(a[1]==a[2]&&a[2]==a[3])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
