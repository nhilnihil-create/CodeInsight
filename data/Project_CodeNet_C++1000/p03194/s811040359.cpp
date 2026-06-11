#include <bits/stdc++.h>
using namespace std;

int main(){
        long N,P;
        long ans;
        cin >> N >> P;
        ans = (long)pow(P,1/(long double)N);
        while(P % (long)pow(ans,N) != 0){
          ans--;
        }
        cout << ans << endl;
        return 0;
}
