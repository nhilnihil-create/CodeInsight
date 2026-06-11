#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>

unsigned int factorial(unsigned int n){
    if (n==0) return 1;
    else return n*factorial(n-1);
}
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans=0;
    for (int i=0;i<n;i++){
        ll Iter=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        ll Iter2=c.end()-upper_bound(c.begin(),c.end(),b[i]);
        ans+=Iter*Iter2;
    }
    cout<<ans<<endl;

    return 0;
}