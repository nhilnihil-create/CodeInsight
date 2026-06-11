#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll i,j;
    ll co=0;
    for(i=0;i<n;i++)cin >> a.at(i);

    for(i=0;i<n-1;i++){
        if(a.at(i)==a.at(i+1)){
            co++;
            a.at(i+1)=1000;
        }
    }
    cout << co << endl;
    return 0;
}