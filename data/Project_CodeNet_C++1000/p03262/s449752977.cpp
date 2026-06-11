#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    ll r;
    if(b > a){
        swap(a, b);
    }
    while((r = a % b)){
        a = b;
        b = r;
    }
    return b;
}


int main(){
    ll n, x, a;
    cin>>n;
    cin>>x;

    vector<ll> v;
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(abs(a-x));
    }

    if(v.size() == 1){
        cout<<v[0]<<endl; 
        return 0;       
    }
    
    vector<ll> ans;
    for(int i=0; i<n-1; i++){
        ans.push_back(gcd(v[i], v[i+1]));
    }

    sort(ans.begin(), ans.end());
    cout<<ans[0]<<endl;

    return 0;
}