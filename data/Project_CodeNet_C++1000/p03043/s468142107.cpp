#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> d(k);
    vector<int> p(k);
    for(int i=1; i<k; i++) d[i]=i;
    for(int index=1; index<=25; index++){
        for(int i=1; i<k; i++){
            if(d[i]<k) {
                d[i] *= 2;
                if(d[i]>=k) p[i] = index;
            }
        }
    }
    
    vector<int> pow2(25);
    pow2[0] = 1;
    for(int i=1; i<25; i++) pow2[i] = pow2[i-1]*2;
    long double ans = 0;
    for(int i=1; i<=n; i++){
        if(k<=i){
            ans += 1.0;
        }
        else{
            ans += 1.0 / (long double)pow2[p[i]];
        }
    }
    ans /= (long double)n;
    printf("%.12Lf\n",ans);
    return 0;
}