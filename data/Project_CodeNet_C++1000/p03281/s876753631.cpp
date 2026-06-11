#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    int count = 0;
    rep2(i,1,n+1){
        if(i%2!=0){
            rep2(j,1,n+1){
                if(i%j==0)count++;
            }
        }
        if(count==8)ans++;
        count = 0;
    }
    
    cout << ans;
    
	return 0;
}