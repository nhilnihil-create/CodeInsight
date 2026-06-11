#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int A,B,T;
    cin >> A >> B >> T;
    
    int ans=0;
    while(true){
        T=T-A;
        if(T>=0){
            ans+=B;
        }else{
            break;
        }
        
    }
    
    cout << ans << endl;
}
