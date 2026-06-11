#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,Q;
    cin >> a >> b >> Q;
    vector<long long>s(a+2),t(b+2);
    s[0]=-(1e11);t[0]=-(1e11);
    s[a+1]=1e12;t[b+1]=1e12;
    for(int i=0;i<a;i++)cin >> s[i+1];
    for(int i=0;i<b;i++)cin >> t[i+1];

    for(int i=0;i<Q;i++){
        long long x;
        cin >> x;
        int l=-1;int r=a+2;
        while(r-l>1){
            int mid=(l+r)/2;
            if(s[mid]<x)l=mid;
            else r=mid;
        }
        int ll=-1;int rr=b+2;
        while(rr-ll>1){
            int mid=(ll+rr)/2;
            if(t[mid]<x)ll=mid;
            else rr=mid;
        }
        long long ans = (1e12);
        ans=min(ans,max(abs(x-s[l]),abs(x-t[ll])));
        ans=min(ans,max(abs(x-s[r]),abs(x-t[rr])));
        ans=min(ans,abs(s[r]-t[ll])+min(abs(x-s[r]),abs(x-t[ll])));
        ans=min(ans,abs(t[rr]-s[l])+min(abs(x-t[rr]),abs(x-s[l])));
        cout << ans << '\n';
    }

    return 0;
}
