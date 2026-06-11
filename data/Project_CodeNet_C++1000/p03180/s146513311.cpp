#include <bits/stdc++.h>
using namespace std;
const int siz = 16;
long long n,sum[(1<<siz)],dp[(1<<siz)],vals[siz][siz];
 
void getsum(int mask){
    vector<int> g;
    for(int i = 0 ; i < n ; i += 1){
        if(mask & (1<<i)){
            g.push_back(i);
        }
    }
    for(int i = 0 ; i+1 < g.size() ; i += 1){
        for(int j = i+1 ; j < g.size() ; j += 1){
            sum[mask] += vals[g[i]][g[j]];
        }
    }
}

long long tryall(int curr , int mask , int val);
 
long long ans(int curr){
    if(curr == 0){
        return 0;
    }
    if(dp[curr] != -1){
        return dp[curr];
    }
    return dp[curr] = tryall(0,0,curr);
}

long long tryall(int curr , int mask , int val){
	if(curr == siz){
		if(mask){
			return sum[mask]+ans(val^mask);
		}
		return 0;
	}
	long long ret;
	if(val & (1<<curr)){
		ret = max(tryall(curr+1,mask,val),tryall(curr+1,mask^(1<<curr),val));
	}else{
		ret = tryall(curr+1,mask,val);
	}
	return ret;
}

int main(){
	memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0 ; i < n ; i += 1){
        for(int j = 0 ; j < n ; j += 1){
            cin >> vals[i][j];
        }
    }
    for(int i = 0 ; i < (1<<n) ; i += 1){
        getsum(i);
    }
    cout << ans((1<<n)-1);
}