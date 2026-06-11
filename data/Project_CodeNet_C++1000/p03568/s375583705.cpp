#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<int> a(n);
    ll i,j;
    ll ev=0,od=0;
    ll iti=0;
    for(i=0;i<n;i++){
        cin >> a.at(i);
        if(a.at(i)%2==1)od++;
        if(a.at(i)%2==0)ev++;
    }
    ll count;
    count = pow(3,n);
    ll odds;
    odds=pow(2,ev);
    cout << count - odds<<endl;
    return 0;
}