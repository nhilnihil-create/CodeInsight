#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,a,x;
    cin>>n>>a;
    x=n%500;
    if(a>=x){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
