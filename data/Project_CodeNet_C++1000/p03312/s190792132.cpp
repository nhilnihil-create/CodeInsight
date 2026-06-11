#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> sum(n);
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll ret=LLONG_MAX;
    for(int i=1;i<n-2;i++){
        ll s=sum[i]/2;
        int x=lower_bound(sum.begin(),sum.begin()+i+1,s)-sum.begin();
        ll t=sum[i]+(sum[n-1]-sum[i])/2;
        int y=lower_bound(sum.begin()+i+1,sum.end(),t)-sum.begin();
        ll b,c,d,e;
        for(int j=max(0,x-1);j<=min(i,x);j++){
            for(int k=max(i+1,y-1);k<=min(n-2,y);k++){
                b=sum[j];
                c=sum[i]-sum[j];
                d=sum[k]-sum[i];
                e=sum[n-1]-sum[k];
                ret=min(ret,max({b,c,d,e})-min({b,c,d,e}));
            }
        }
    }
    cout<<ret<<endl;
}