#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll k(ll n){
ll p=0;
while(n%2==0){
    p++;n/=2;
}
return p;

}

int main() {

    int n;
    cin>>n;
    int e=0;
    for(ll i=1;i<=n;i++){
        ll temp;
        cin>>temp;
        e+=k(temp);

    }
cout<<e;
 return 0;
}
