#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);


const int N=105;
ll powers[N];
ll primes[N];


void sieve()
{
  
  
  for(ll i=2;i<=N;i++)
  {
    if(primes[i]==-1)
    {
        for(ll j=i;j<=N;j+=i) primes[j]=i;
        
     }
   }

}

int main(){
    ll n;
    IOS
    cin>>n;
    fo(i,N){
        primes[i]=-1;
        powers[i]=0;
    }
  
    set<ll> st;
    ll tmp=1;
    sieve();
    FOR(i,2,n){
        ll tmp=i;
        while(tmp>1){
            ll y=primes[tmp];
            ll count=0;
            st.insert(y);

            while(tmp%y==0){
                tmp=tmp/y;
                count++;
            }
            powers[y]=(powers[y]+count); 
        }
    }
    //dbg("vfdvfd");
    std::vector<ll> primes;
    for(auto oo:st){
    	primes.pb(oo);
    	//dbg2(oo,powers[oo]);
    }
    ll ans=0;
    ll nn=sz(primes);
    fo(i,nn){
    	if(powers[primes[i]]>=14){
    		fo(j,nn){
    			if(j!=i&&powers[primes[j]]>=4){
    				ans++;
    			}
    		}
    	}
    }
    fo(i,nn){
    	if(powers[primes[i]]>=24){
    		fo(j,nn){
    			if(j!=i&&powers[primes[j]]>=2){
    				ans++;
    			}
    		}
    	}
    }
    fo(i,nn){
    	if(powers[primes[i]]>=74){
    		ans++;
    		
    	}
    }
    fo(i,nn){
    	if(powers[primes[i]]>=4){
    		FOR(j,i+1,nn-1){
    			if(j!=i&&powers[primes[j]]>=4){
    				fo(k,nn){
    					if(k!=i&&k!=j&&powers[primes[k]]>=2){
    						ans++;
    						//dbg3(i,j,k);
    					}
    				}
    			}
    		}
    	}
    }
    cout<<ans<<endl;




  }