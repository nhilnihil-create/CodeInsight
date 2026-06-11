#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    if(k%2)cout<<(n/k)*(n/k)*(n/k)<<endl;
    else cout<<(n/k)*(n/k)*(n/k)+((n+k/2)/k)*((n+k/2)/k)*((n+k/2)/k)<<endl;
    return 0;
}