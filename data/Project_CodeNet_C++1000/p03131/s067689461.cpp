#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k,a,b;  cin >> k >> a >> b;

    if(b-a<=2){
        cout << k+1 << endl;
        return 0;
    }

    long long  ans=1;

    k -= a-1;
    ans+=a-1;
    ans+=(k/2)*b;
    ans-=(k/2)*a;
    ans+=k%2;

    cout << ans << endl;
}