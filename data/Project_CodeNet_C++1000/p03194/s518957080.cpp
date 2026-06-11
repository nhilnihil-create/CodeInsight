#include <bits/stdc++.h>
using namespace std;

int main(){
        long double N,P;
        unsigned long long ans;
        cin >> N >> P;
        ans = (unsigned long long)pow(P,1/N);
        while((unsigned long long)P % (unsigned long long)pow(ans,N) != 0){
          ans--;
        }
        cout << ans << endl;
        return 0;
}
