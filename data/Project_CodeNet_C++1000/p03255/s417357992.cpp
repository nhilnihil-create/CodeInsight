    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define rep(i,s,n) for(int i = s; i < n; i++)
    const ll maxn = 2e5+10;
    ll N,X;
    ll in[maxn];
    ll cumsum[maxn];
    double ans = 1e100;
     
    int main(){
    	cin>>N>>X;
    	rep(i,0,N){
    		scanf("%lld", &in[i+1]);
    	}
    	cumsum[1] = in[1];
    	rep(i,2,N+1){
    		cumsum[i] = cumsum[i-1]+in[i];
    	}
    	rep(k,1,N+1){
    		double tmp=0.0;
    		for(int i = N; i >=0; i-=k){
    			if(i==N) tmp+=5*cumsum[i];
    			else if(N-k==i)continue;
    			else tmp+=2*cumsum[i];
    		}
    		tmp+=X*N+k*X;
    		// cout<<tmp<<endl;
    		ans = min(ans,tmp);
    	}
    	cout<<(ll)ans<<endl;
    }