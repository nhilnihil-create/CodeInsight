#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[105];
ll MAX,MIN;
int main(void){
    cin>>n;
    cin>>a[0];
    MAX=a[0];
    MIN=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        MAX=max(MAX,a[i]);
        MIN=min(MIN,a[i]);
    }
    cout<<MAX-MIN<<endl;

}

