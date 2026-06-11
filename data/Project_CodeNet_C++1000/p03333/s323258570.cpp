    #include<cstdio>
    #include<algorithm>
    using namespace std;
    typedef long long ll;
    const ll Kmax=1e6+15;
    ll right[Kmax];
    ll left[Kmax];
    bool cmp(ll a,ll b){
    	return a>b;
    }
    int main(){
    	ll n;
    	scanf("%lld",&n);
    	for(ll i=0;i<n;i++){
    		scanf("%lld",&left[i]);
    		scanf("%lld",&right[i]);
    	}
    	sort(left,left+n,cmp);
    	sort(right,right+n);
    	long long loc=0;
    	long long ans1=0;
    	long long ans2=0;
    	for(ll i=0;i<n;i++){
    		if(loc>=left[i]){
    			break;
    		}
    		ans1+=left[i]-loc;
    		loc=left[i];
    		if(loc<=right[i]){
    			break;
    		}
    		ans1+=loc-right[i];
    		loc=right[i];
    	}if(loc<0)loc=-loc;
    	ans1+=loc;
    	
    	loc=0;

    		for(ll i=0;i<n;i++){
    		if(loc<=right[i]){
    			break;
    		}
    		ans2+=loc-right[i];
    		loc=right[i];
    		if(loc>=left[i]){
    			break;
    		}
    		ans2+=left[i]-loc;
    		loc=left[i];
    	}

    	if(loc<0)loc=-loc;
    	ans2+=loc;
    	printf("%lld\n",max(ans1,ans2));
    	return 0;
    }
