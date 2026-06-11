#include <bits/stdc++.h>
using namespace std;

signed main(){
    long long n , a , m = 0;
    cin >> n ;
    
    for(int i=0 ;i<5 ;i++ ){
        cin >> a;
        m = max(m , (n-1)/a);
    }
    
    cout << m+5 << endl;
    return(0);
}
