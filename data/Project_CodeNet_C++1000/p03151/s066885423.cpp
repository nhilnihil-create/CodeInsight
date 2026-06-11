#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    int N; cin >> N;
    vector<ll> a(N); vector<ll> b(N);
    vector<ll> gap(N);
    ll tarinai=0;
    ll ans=0;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<N;i++){
        cin >> b[i];
        gap[i]=a[i]-b[i];
        if(gap[i]<0) {tarinai-=gap[i]; ans++;}
    }
    sort(gap.begin(), gap.end());
    reverse(gap.begin(), gap.end());
    int idx=0;
    while(tarinai>0){
        if(gap[idx]<=0) {ans=-1; break;}
        tarinai -= gap[idx];
        ans++; idx++;
    }
    cout << ans << endl;    
}

