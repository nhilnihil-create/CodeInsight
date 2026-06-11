#include<bits/stdc++.h>
using namespace std;
int a[100];
long long ans[405][405];
long long int counter(int l, int r){
    if(l==r){
        return 0;
    }
    if(ans[l][r] != -1)
        return ans[l][r];
    long long int minres = -1;
    long long int sum = 0;
    for(int i=l; i<r; i++){
        sum = sum + a[i];
        if(minres == -1)
            minres = counter(l,i)+counter(i+1,r);
        else
            minres = min(minres,counter(l,i)+counter(i+1,r));
    }
    // cout << l << " " << r << " " << minres+sum+a[r] << "\n";
    return ans[l][r] = minres+sum+a[r];
}
int main(){
    int n;
    cin >> n;
    memset(ans, -1, sizeof(ans));
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << counter(0,n-1);
    return 0;
}