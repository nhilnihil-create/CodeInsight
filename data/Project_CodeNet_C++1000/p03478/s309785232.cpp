#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    long int sum;
    long int ans=0;
    int num;
    for(int i=1; i<=n; i++){
        sum=0;
        num=i;
        for(int j=0; j<5; j++){
            sum+=num%10;
            num/=10;
        }
        if(a<=sum && sum<=b){
            ans+=i;
            //cout << i << endl;
        }
    }
    cout << ans << endl;
}