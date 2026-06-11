#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c;
int x[3];
int main(){
    for(int i=0;i<3;i++ ){
        cin>>x[i];
    }
    sort(x, x + 3);
    if(x[0]==x[1]){
        cout<<x[2]<<endl;
    } else{
        cout<<x[0]<<endl;
    }
}