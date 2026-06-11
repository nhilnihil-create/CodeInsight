#include <iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    long long l1,l2;
    l1=2;l2=1;
    if (n==1){
        cout<<1;
        exit(0);
    }
    else if (n==2){
        cout<<3;
        exit(0);
    }
    for (int i =0;i<n-1;i++){
        long long tmp;
        tmp=l2;
        l2+=l1;
        l1=tmp;
    }
    cout<<l2;
    
}
