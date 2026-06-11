#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    for(int i=0; i<n; i++){
        cin >> b.at(i);
    }
    for(int i=0; i<n; i++){
        cin >> c.at(i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int> b_cnt(n);
    for(int i=0; i<n; i++){
        int check=b.at(i);
        int l=-1;
        int r=n;
        while(r>l+1){
            int mid=(l+r)/2;
            if(c.at(mid)>check) r=mid;
            else l=mid;
        }
        b_cnt.at(i)=n-r;
    }
    vector<ll> b_sum(n);
    b_sum.at(n-1)=b_cnt.at(n-1);
    for(int i=n-2; i>=0; i--){
        b_sum.at(i)=(ll)b_cnt.at(i) + (ll)b_sum.at(i+1);
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        int check=a.at(i);
        int l=-1;
        int r=n;
        while(r>l+1){
            int mid=(l+r)/2;
            if(b.at(mid)>check) r=mid;
            else l=mid;
        }
        if(r==n) continue;
        ans += b_sum.at(r);
    }
    cout << ans << endl;
}