#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    ll a,b,k;
    cin >> a >> b >> k;
    
    rep(i,k/2){
        if(a%2==1)a--;
        b+=a/2;
        a/=2;
        if(b%2==1)b--;
        a+=b/2;
        b/=2;
    }
    if(k%2==1){
        if(a%2==1)a--;
        b+=a/2;
        a/=2;
    }
    cout << a <<" "<< b << endl;
} 

    