#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++) cin>>b[j];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> v;
    for(int k=0;k<30;k++){
        // k-bit 目の答え
        ll t=(1<<k),cnt=0;
        vector<ll> btmp;
        for(int i=0;i<n;i++) btmp.push_back(b[i]%(1<<(k+1)));
        sort(btmp.begin(),btmp.end());
        for(int i=0;i<n;i++){
            ll atmp=a[i]%(1<<(k+1));
            auto st=lower_bound(btmp.begin(),btmp.end(),t-atmp);
            auto gt=lower_bound(btmp.begin(),btmp.end(),2*t-atmp);
            cnt += distance(st,gt);

            st=lower_bound(btmp.begin(),btmp.end(),3*t-atmp);
            gt=lower_bound(btmp.begin(),btmp.end(),4*t-atmp);
            cnt += distance(st,gt);
        }
        //cout<<k<<" "<<cnt<<endl;
        v.push_back(cnt%2);
    }
    ll res=0;
    for(int i=(int)v.size()-1;i>=0;i--){
        res *= 2;
        if(v[i]) res++;
    }
    cout<<res<<endl;
}
