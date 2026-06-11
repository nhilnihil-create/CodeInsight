#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int main(){
    ll n;
    cin >> n;
    int i,j;
    ll go=1e6;
    for(i=1;i<n;i++){
        ll n1,n2;
        ll sum=0;
        n1=i;
        n2=n-i;
        while(n1!=0){
            sum+=n1%10;
            n1/=10;
        }
        while(n2!=0){
            sum+=n2%10;
            n2/=10;
        }
        go=min({go,sum});
    }
    cout << go << endl;
    return 0;
}