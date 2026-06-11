#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;
const ll inf2 = 1000000000000000000;


    int main (){
        ll a,b,c,k;
        cin >> a >> b >> c >> k;
        ll ans =0;
        if(k%2==0){
            ans=a-b;
        }
        else{
            ans=b-a;
        }
       
        cout << ans << endl;
        return 0;
    }