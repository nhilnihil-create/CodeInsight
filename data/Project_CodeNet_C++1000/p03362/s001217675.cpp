#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

const ll inf = 1e18;

bool is_prime(int n){
    if(n == 1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    vector<int>ans;
    for(int i=1;i<=55555;i++){
        if(!is_prime(i))continue;
        if(i%5 == 1) ans.push_back(i);
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << endl;
}