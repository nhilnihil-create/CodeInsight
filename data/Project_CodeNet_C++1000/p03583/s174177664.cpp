#include<iostream>
using namespace std;

int main() {
    long N;
    cin>>N;
    long ansh, ansn, answ;
    for(long h=1;h<=3500;++h){
        for(long n=1;n<=3500;++n){
            if(4*h*n-N*n-N*h>0){
                if((N*h*n)%(4*h*n-N*n-N*h)==0){
                    ansh = h;
                    ansn = n;
                    answ = N*h*n/(4*h*n-N*n-N*h);
                    break;
                }
            }
        }
    }
    cout<<ansh<<" "<<ansn<<" "<<answ<<endl;
}
