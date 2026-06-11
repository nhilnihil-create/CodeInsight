#include<iostream>
#include<cmath>
using namespace std;

using lint = long long int;


int main(){
    int Q;
    lint A,B;

    cin >> Q;
    for(int i=0;i<Q;i++){
        lint ans = 0;
        cin >> A >> B;
        lint AB = A*B;
        lint rootnumber = sqrt(AB);
        ans += (rootnumber-1)*2;

        if(rootnumber*(rootnumber+1)<AB){
            ans += 2;
            if(A<=rootnumber+1) ans--;
            if(B<=rootnumber+1) ans--;
        }
        else if(rootnumber*rootnumber<AB){
            ans++;
            if(A<=rootnumber) ans--;
            if(B<=rootnumber) ans--;
            if(A==rootnumber && B==rootnumber) ans++;
        }
        else{
            if(A<rootnumber) ans--;
            if(B<rootnumber) ans--;
        }
        cout << ans << "\n";
    }

    return 0;
}