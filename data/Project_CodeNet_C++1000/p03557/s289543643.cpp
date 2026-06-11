#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    int n;
    long ans=0l;
    sc1(n);
    vector <int> a(n);
    vector <int> b(n);
    vector <int> c(n);
    rep(i,n) sc1(a[i]);
    rep(i,n) sc1(b[i]);
    rep(i,n) sc1(c[i]);
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    rep (i,n) {
        //printf("%ld %d\n",lower_bound(a.begin(),a.end(),b[i])-a.begin(),n-*upper_bound(c.begin(),c.end(),b[i]));
        ans+=(lower_bound(a.begin(),a.end(),b[i])-a.begin())*(c.end()-upper_bound(c.begin(),c.end(),b[i]));
        //ans+=*lower_bound(a.begin(),a.end(),b[i])*(n-*upper_bound(c.begin(),c.end(),b[i])+1);
    }
    printf("%ld\n",ans);
    return 0;
}
