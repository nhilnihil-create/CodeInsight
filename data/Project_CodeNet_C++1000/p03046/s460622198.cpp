//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
const int MAXN=2e5+9;
const double eps=1e-8;
const long double pi=3.1415926535897932384626433832795;
const long double e=2.71828182845904523536028747135266;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(n==1){
            if(!k) cout << "0 0 1 1" << endl;
            else cout << -1 << endl;
        }
        else if(k>=(1<<n)) cout << -1 << endl;
        else {
            for(int i=0;i<(1<<n);i++){
                if(i!=k) cout << i << " ";
            }
            cout << k << " ";
            for (int i=1<<n;i--;){
                if(i!=k) cout << i << " ";
            }
            cout << k << endl;
        }
    }
    return 0;
}
