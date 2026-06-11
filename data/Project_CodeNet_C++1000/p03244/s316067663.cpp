#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    vector<long long> b(100001,0);
    vector<long long> c(100001,0);
    for(long long i=0;i<n;i++){
        cin >> a[i];
        if(i%2==0) b[a[i]]++;
        else c[a[i]]++;
    }
    long long d1=0,d2=0,e1=0,e2=0;
    for(long long i=0;i<100001;i++){
        if(b[i]>=b[d1]){
            d2=d1;
            d1=i;
        }
        if(b[i]<b[d1]&&b[i]>b[d2]) d2=i;
        if(c[i]>=c[e1]){
            e2=e1;
            e1=i;
        }
        if(c[i]<c[e1]&&c[i]>c[e2]) e2=i;
    }
    long long res;
    if(d1!=e1) res=n-b[d1]-c[e1];
    else res=min(n-b[d2]-c[e1],n-b[d1]-c[e2]);
    cout << res << endl;
}
