#include <iostream>

using namespace std;

int main()
{
    int x[3];
    for(int i =0 ;i<3;i++){
        cin >> x[i];
    }
    if(x[0]==x[1]){
        cout<<x[2];
    }
    else if(x[1]==x[2]){
        cout<<x[0]<<endl;
    }
    else{cout<<x[1]<<endl;}


    return 0;
}
