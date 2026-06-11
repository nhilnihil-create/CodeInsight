#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long N, P, i, j, ans=0;

    cin >> N >> P;
    if (N==1) ans = P;
    else{
        for (i=1; i<=sqrt(P)+1; i++){
            j = pow(i, N);
            if (j <= P){
                if (!(P % j)) ans = i;
            }
            else break;
        }
    }


    cout << ans << '\n';

}