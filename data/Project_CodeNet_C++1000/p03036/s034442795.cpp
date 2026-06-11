#include <iostream>
using namespace std;
int main(void){
    int r,D,x;
    cin>>r>>D>>x;
    for(int i=1;i<11;i++){
        cout<<r*x-D<<endl;
        x=r*x-D;
    }
}
