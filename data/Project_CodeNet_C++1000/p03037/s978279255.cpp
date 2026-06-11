#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int M, N,i,j, L, R;
    cin >> N >> M;
    int L_temp = 1;
    int R_temp = N;

    for(i = 0;i<M;i++){        
        cin >> L >> R;
        L_temp=max(L,L_temp);
        R_temp=min(R,R_temp);
        if(R_temp-L_temp<0){
            cout << 0 <<endl;
            return 0;
        }
    }

    cout << R_temp-L_temp + 1 << endl;
    return 0;

}