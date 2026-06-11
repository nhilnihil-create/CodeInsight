#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)



int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    ll ans=0;
    int r=0;
    ll sum_xor=0;
    ll sum_plus=0;
    rep(l,N){   
        while(r<N&&((sum_xor^a[r])==(sum_plus+a[r]))){
            sum_xor^=a[r];
            sum_plus+=a[r];
            r++;
        }

        ans+=(r-l);
        if(l==r) r++;
        else{
            sum_xor^=a[l];
            sum_plus-=a[l];
        }
        
    }
    
    cout << ans << endl;
    
}