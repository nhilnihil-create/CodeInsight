#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    ll N,K;
    cin>>N>>K;
    ll t=K*1900+(N-K)*100;
    cout<<t*pow(2,K);
}