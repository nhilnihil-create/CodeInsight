#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll (i)=0;(i)<(ll) (n);(i)++)
int main(void){
    ll n,i=0,j,p,h[1000010],k;
    double c=1,kaku=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        j=i;
        while(j<k)
        {
            c=c/2;
            j=j*2;
        }
        kaku+=c/n;
        c=1;
    }
    cout << fixed << setprecision(12);
    cout << kaku << endl;
    return 0;

}
