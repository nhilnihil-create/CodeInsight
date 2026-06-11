#include <bits/stdc++.h>
 
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
    int n,k; cin >> n >> k;
    int t;
    if(n%2 == 0) {
        t = n/2;
    }
    else{
        t = n/2+1;
    }
    if(t >= k){
        cout << "YES" << endl;
        
    }else{
        cout << "NO" << endl;
    }
    return 0;
    

}
