#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int l[n],r[n];
    for(int i=0;i<n;i++){
        cin >> l[i] >>r[i];

    }
    sort(l,l+n,greater<int>());
    sort(r,r+n);
    int ans=0;
    int ansmax=0;
    for(int i=0;i<n;i++){
        if(ansmax<ans+2*l[i])ansmax=ans+2*l[i];
        if(ansmax<ans-2*r[i])ansmax=ans-2*r[i];
        ans+=2*l[i]-2*r[i];
          if(ansmax<ans)ansmax=ans;
         
        
            
        
    }
    cout << ansmax;
    return 0;
}