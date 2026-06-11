    #include <bits/stdc++.h>
    #define INF (1<<30)
    #define MOD 1000000007
    #define l_ength size
    using ll = long long;
    using namespace std;
     
    int main(){
    	 int n; cin >> n;
    	 vector<ll> a(n);
    	 for( auto &k : a ) cin >> k;
    	 bitset<4000005> x;
    	 x.set(0);
    	 for( int i = 0; i < n; ++i ){
    		 x |= ( x << a[i] );
    	 }
    	 int sum = accumulate( a.begin(), a.end(), 0 );
    	 int bound = (sum+1)/2;
    	 for( int i = bound; i <= sum; ++i ){
    		 if( x.test(i) ){
    			 cout << i << endl;
    			 break;
    		 }
    	 } 
    	return 0;
    }