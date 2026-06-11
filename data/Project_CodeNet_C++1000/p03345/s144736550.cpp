#include <iostream>
using namespace std;
int main(void){
    long long a,b,c,k;
    cin>>a>>b>>c>>k;
    if (abs(a-b)>1000000000000000000){
    cout<<("Unfair");}
    else{
        if (k%2==0){
    cout<<(a-b);}
    else{
        cout<<(b-a);
    }
        
    }
}
