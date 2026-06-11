#include<iostream>
using namespace std;

int main() {
    long N;
    cin>>N;
    long ans = 0;
    long m = 1;
    while(true){
        if(N/m <= m) break;
        else {
            if(N%m==0){
                if(N%(N/m-1)==0){
                    m++;
                    continue;
                }
                ans += N/m-1;
            }
        }
        m++;
    }
    cout<<ans<<endl;
}
