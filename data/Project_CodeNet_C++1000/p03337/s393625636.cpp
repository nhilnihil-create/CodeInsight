#include <iostream>

using namespace std;

int main() {
    int z,x,c,v,b;
    int maximum;
    cin>>z>>x;
    c=z+x;
    v=z-x;
    b=z*x;
    maximum=c;
    if(maximum<v){
        maximum=v;
    }
    if(maximum<b){
        maximum=b;
    }
    cout<<maximum<<"\n";
    return 0;
}