#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int N,K;
    cin >> N >> K;
    
    if(N%2==0){
        if(N/2>=K){
            cout << "YES" << endl;
            return 0;
        }
    }else{
        if(N/2+1>=K){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    
    return 0;
}
