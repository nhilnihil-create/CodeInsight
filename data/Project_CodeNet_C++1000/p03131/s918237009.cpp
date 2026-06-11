#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int k,a,b; cin >> k >> a >> b;
    ll B = 1;
    for(int i = 0; i < k; i++){
        if(b-a <= 2 || i == k-1){
            B++;
        }else{
            if(B >= a){
                B+=(b-a); i++;
            }else{
                B++;
            }
        }
    }
    cout << B << endl;
    return 0;
}