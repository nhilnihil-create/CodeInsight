#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"Christmas"<<" ";
        for(int i=0;i<abs(25-n);i++){
            cout<<"Eve"<<" ";
        }
    }   
    return 0;
}
