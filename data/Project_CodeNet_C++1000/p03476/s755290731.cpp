#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int main(){
    ll int n,a[100001],b[100001],c[100001],l[100001],r[100001];
    c[0]=0;
    for (int i=1;i<100001;i++){
        if(isPrime(i)){
            a[i]=1;
            if(a[(i+1)/2]==1){
                b[i]=1;
            }else{
                b[i]=0;
            }
        }else{
            a[i]=0;
            b[i]=0;
        }
        c[i]=c[i-1]+b[i];
    }
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> l[i] >> r[i];
        cout << c[r[i]]-c[l[i]-1] << endl;
    }
    
}