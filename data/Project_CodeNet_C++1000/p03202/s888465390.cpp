#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1000000;
const int MOD = 1000000007;

signed main() {
 int n;
 cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i-1]>=a[i])break;
        if(i==n-1){
            cout<<1;
            return 0;
        }
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    int ok=n,ng=1,mid,j;
    map<int,int> mp;
    while(abs(ok-ng)>1){
        mp.clear();
        mid=(ok+ng)/2;
        for(int i=1;i<n;i++){
            if(a[i-1]<a[i])continue;
            while(mp.size()>0&&mp.rbegin()->first>=a[i])mp.erase((next(mp.rbegin())).base());
            //mp.erase(mp.lower_bound(a[i]),mp.end());
            j=a[i]-1;
            mp[j]++;
            while(j>0&&mp[j]==mid){
                mp[j]=0;
                j--;
                mp[j]++;
            }
            if(mp[0]>=mid)break;
        }
        if(mp[0]>=mid)ng=mid;
        else ok=mid;
    }
    cout<<ok;
return 0;
}
