#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    int n;
    cin >>n;
    vector<int> a(n);
    cin >> a[0];
    int t;
    for(int i=1;i<n;i++){
        cin >> t;
    a[i]= t+a[i-1];
    }
    int p=0,q=2,ans=-1;
    for(int i=1;i<n-2;i++){
       while(abs(a[i]-2*a[p])>abs(a[i]-2*a[p+1]))p++;
       while(abs(a[n-1]+a[i]-2*a[q])>abs(a[n-1]+a[i]-2*a[q+1]))q++;
        if(ans<0||ans>max(max(a[p],a[i]-a[p]),max(a[q]-a[i],a[n-1]-a[q]))-min(min(a[p],a[i]-a[p]),min(a[q]-a[i],a[n-1]-a[q])))ans=max(max(a[p],a[i]-a[p]),max(a[q]-a[i],a[n-1]-a[q]))-min(min(a[p],a[i]-a[p]),min(a[q]-a[i],a[n-1]-a[q]));

       // cerr << ans<< ' '<<p <<' '<<q<<endl;
        
    }

    
    cout << ans;
    return 0;
}