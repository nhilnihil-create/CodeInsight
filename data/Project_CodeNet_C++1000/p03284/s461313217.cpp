#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n,k,min,min1;
    cin>>n>>k;
    if (n%k==0){
        cout<<"0\n";
        return 0;
    }
    else{
        min=n/k;
        min1=min+1;
        cout<<abs(min-min1)<<endl;
    }
    return 0;
}