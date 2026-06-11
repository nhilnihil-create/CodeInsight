#include <iostream>
using namespace std;
int main(void){
    string n;
    cin>>n;
    int ans =0;
    for (int i=0;i<4;i++){
        ans+=(n[i]=='2');
    }
    cout<<ans;
};
