#include<bits/stdc++.h>

typedef int i32;
typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;


template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};


#define debug(x)  cerr<<x<<"\n";
#define loop(i,n) for(i32 i = 0; i < n; ++i)
#define pi  pair<i32,i32>
#define ti  triple<i32,i32,i32>
#define mk  make_pair
#define vi  vector<i32>
#define vll vector<i64>
#define fastInOut ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pr(a) for(auto x:a) cout<<x<<" ";
#define prmap(m) for(auto x:m) cout<<x.first<<" "<<x.second<<"\n";
using namespace std;

bool isPrime(i64 x){
	
	for(i64 i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

vi V;
const i32 N=7e7+9;
bool prime[N]; 
void SieveOfEratosthenes() 
{
    for (int  p=2; p*p<=N; p++){ 
        if (prime[p] == false){ 
            for (int  i=p*p; i<=N; i += p) 
                prime[i] = true; 
        } 
    } 
    int u=0,mx=0;
    for (int p=2; p<=N; p++) 
      if (!prime[p]) {
          V.push_back(p);
    }
   
}
i64 a,k,w,c=0;
void solve(){
    cin>>a>>k;
    if(k>=a)
      cout<<a;
    else
       cout<<a-1;
}

int main(){
    fastInOut
    solve();
    return 0;
}
