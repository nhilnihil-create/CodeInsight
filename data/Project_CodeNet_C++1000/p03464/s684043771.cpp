#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
    int k,i,a[100005];
    ll l,r,mid,th,nmax,nmin;
    
    cin >> k;
    for (i=0;i<k;i++) cin >> a[i];
    
    l=0;
    r=1e18;
    while (r-l>1){
        mid=(l+r)/2;
        th=mid;
        for (i=0;i<k;i++){
            th-=th%a[i];
        }
        if (th>=2) r=mid;
        else l=mid;
    }
    
    nmin=r;
    
    l=0;
    r=1e18;
    while (r-l>1){
        mid=(l+r)/2;
        th=mid;
        for (i=0;i<k;i++){
            th-=th%a[i];
        }
        if (th<=2) l=mid;
        else r=mid;
    }
    
    nmax=l;
    
    if (nmax<nmin) cout << -1 << endl;
    else cout << nmin << ' ' << nmax << endl;
    
    return 0;
}