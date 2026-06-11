#include<bits/stdc++.h>
using namespace std;

int main(void){
    int q,n = 0;
    cin >> q;
    int l[q],r[q];
    for(int i = 0;i < q;i++){
        cin >> l[i] >> r[i];
        n = max(n,r[i]);
    }
    
    int is_prime[100005] = {},num[100005] = {};
    
    for(int i = 2;i <= n;i++){
        if(!is_prime[i]){
            for(int j = 2*i;j <= 100000;j += i)is_prime[j] = 1;
        }
    }
    for(int i = 3;i <= n;i++){
        if(is_prime[i] == 0 && is_prime[(i+1)/2] == 0)num[i] += num[i-1] + 1;
        else num[i] += num[i-1];
    }
    
    for(int i = 0;i < q;i++)cout << num[r[i]]-num[l[i]-1] << endl;
}