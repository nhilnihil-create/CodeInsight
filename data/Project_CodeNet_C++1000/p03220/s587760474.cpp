#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int N,T,A;
int H[1200];

int main(){
    cin >>N;
    cin >>T>>A; //初期値
    int Mind=2000000;

    for (int i=1;i<N+1;++i) cin >>H[i];
    int res=1;

    for (int i=1;i<N+1;++i){
        int d=(T*1000-H[i]*6)-A*1000;
        if(d<0) d=-d;

        if(d<Mind){
            Mind=d;
            res=i;
        }      
    }

    cout <<res<<endl;
    return 0;
}