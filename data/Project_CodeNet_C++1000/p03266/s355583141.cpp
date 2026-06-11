#include<iostream>
#include<cmath>
using namespace std;
int min_num(int x){
    if(x%2 == 0)return x/2;
    else return x;
}
int main(void){
    int n,k;
    cin>>n>>k;
    long long ans(0);
    for(int i(1);i<=n;i++){
        if(i%min_num(k) == 0){
            long long num = (n-i)/k + 1;
            ans += (long long)pow(num,3) - (long long)pow(num-1,3);
        } 
    }
    cout<<ans<<endl;
    return 0;
}