#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    ll a,b,k; cin >> a >> b >> k;
    for(int i = 0; i < k; i++){
        if(i%2 == 0){
            b += a/2; a/=2;
        }else{
            a += b/2; b/=2;
        }
    }
    cout << a << " " << b << endl;
    return 0; 
}