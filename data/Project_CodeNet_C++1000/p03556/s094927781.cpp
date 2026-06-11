#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    while(cnt*cnt<=n){
        cnt++;
    }
    
    cout<<(cnt-1)*(cnt-1)<<endl;
    return 0;
}