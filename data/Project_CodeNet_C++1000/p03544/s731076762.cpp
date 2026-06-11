#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t L0=2;
    int64_t L1=1;
    int64_t Ln;
    int N;
    cin>>N;
    if(N>1){
        for(int i=1;i<N;i++){
            Ln=L0+L1;
            L0=L1;
            L1=Ln;
        }
        cout<<Ln<<endl;
    }else{
        cout<<L1<<endl;
    }
  

}

