#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(void){
    
    long long A,B,C;
    cin >> A >> B >> C;
    
    long long ans;
    ans  = B;
    
    if(C<=A+B)ans += C;
    else ans += B + A + 1;
    
    cout << ans << endl;
    
}