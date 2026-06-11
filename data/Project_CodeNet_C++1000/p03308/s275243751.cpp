#include <iostream>
#include <string>

using namespace std;

int A[200];
int N;

int main(){
    
    cin >>N;
    for (int i=0;i<N;++i) cin >>A[i];

    int MaD=0;

    for (int i=0;i<N;++i){
        for (int j=0;j<N;++j){
            if(MaD<A[i]-A[j]) MaD=A[i]-A[j];
        }

    }

    cout <<MaD<<endl;

}