#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int N,A,B;
    cin >> N >> A >> B;
    
    if((B-A)%2 == 0){
        cout << "Alice" << endl;
    }else{
        cout << "Borys" << endl;
    }
    
    return 0;
}
