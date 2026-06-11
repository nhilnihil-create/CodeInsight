#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    ll A,B;
    cin >> A >> B;
    ll sumA=0, sumB=0;
    
    if(A%2==0){
        if((A/2)%2==1){
            sumA=1;
        }else{
            sumA=0;
        }
    }else if(A%2==1){
        if((A/2)%2==1){
            sumA=1 ^ (A-1);
        }else{
            sumA=0 ^ (A-1);
        }
    }
    
    if(B%2==1){
        if((B/2)%2==1){
            sumB=0;
        }else{
            sumB=1;
        }
    }else if(B%2==0){
        if((B/2)%2==1){
            sumB=1 ^ B;
        }else{
            sumB=0 ^ B;
        }
    }
    ll ans = sumA ^ sumB;
    //cout << sumA << endl;
    //cout << sumB << endl;
    cout << ans << endl;

    
}

