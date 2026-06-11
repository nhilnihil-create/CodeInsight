#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A, B, C, D;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    for(int i=0;i<N;i++) {
        //cout << "i : " << i+1 << endl;
        if(A[i]-B[i]>=0&&B[i]<=D[i]) {
            ll dlt = gcd(B[i], D[i]);
            //cout << "gcd : " << dlt << endl;
            ll init = (A[i]-B[i])%dlt;
            if(init<0) init += dlt;
            //cout << "init : " << init << endl;
            ll num = (min(A[i],C[i]+1)-B[i])%dlt;
            if(num<0) num += dlt;
            //cout << "num : " << num << endl;
            ll minv = min(A[i],C[i]+1)-B[i]+init-num;
            if(init-num<0) minv += dlt;
            //cout << "minv : " << minv << endl;
            if(minv>=0) {
                cout << "Yes" << endl;
                continue;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}