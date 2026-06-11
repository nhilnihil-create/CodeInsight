#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    ll ans=0;
    for(auto p: cnt){
        int x,num;
        x = p.first;
        num= p.second;
        if(num>=x) ans+=(ll)(num-x);
        else ans+=(ll)num;
    }
    cout << ans << endl;
}