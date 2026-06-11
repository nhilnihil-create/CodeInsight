#include <iostream>
using namespace std;

int main(){
    int k, a, b;
    cin >> k >> a >> b;
    
    if(b-a >= 3 && k > a-1){
        long long int ans = a;
        ans += (long long int)(b-a)*((long long int)(k-a+1)/2);
        if((k-a+1) % 2) ans++;
        cout << ans << endl;
    }else{
        cout << k+1 << endl;
    }
    return 0;
}