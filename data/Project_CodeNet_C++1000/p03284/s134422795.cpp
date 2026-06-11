#include <iostream>
using namespace std;
int main() {
    int N,K,d;
    cin>>N>>K;
    d=N%K;
    if(d==0){
    cout<<"0";    
    }else{
        cout<<"1";
    }
    return 0;
}
