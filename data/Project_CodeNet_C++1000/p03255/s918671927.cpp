#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    long long n, k;
    cin >> n >> k;
    long long x[n];
    long long sum[n+1] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum[i+1] = sum[i] + x[i];
    }
    long long ans=9e18;
    for(int i=1;i<=n;i++){
        long long ret = i * k;
        long long cnt=3;
        
        //cerr << ret << endl;
        for(int j = n; j >= 0; j-=i){
            ret += (sum[j] - sum[max(0, j - i)]) * max(5LL, cnt);
            if(ret >= ans) break;
            //cerr << (sum[j] - sum[j - 2 * i]) << endl;
            cnt+=2;;
        }
        
        ans = min(ans, ret);
        //cerr << i << " " << ans << " " << ret << endl;
    }
    ans += n * k;
    cout << ans << endl;
    
    
}