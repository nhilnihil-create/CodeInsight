#include <iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    for (int i =0;i<=n/4;i++){
        if ((n-i*4)%7==0){
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
    exit(0);
}
