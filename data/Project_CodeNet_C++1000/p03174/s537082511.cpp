#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
int a[25][25];
int ans[25][1<<21];
long long int ways(int i, int val){
    if(i==n){
        if(val==((1<<n)-1))
            return 1;
        return 0;
    }
    if(ans[i][val] != -1)
        return ans[i][val];
    // cout << i << " " << val << "\n";
    long long int sum = 0;
    for(int j=0;j<n;j++){
        if(a[i][j] && !(val&(1<<j))){
            sum = (sum + ways(i+1,val|(1<<j)%mod))%mod;
        }
    }
    return ans[i][val] = sum;
}
int main(){
    cin >> n;
    memset(ans, -1, sizeof(ans));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    cout << ways(0,0);
}