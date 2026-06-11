#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2147483647
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;

vector<int> prime;
map<ll,int> prco;
void prfac(ll n){
	ll a=2;
	while(n>=a*a){
		if(n%a==0){
			//prime.push_back(a);
			n/=a;
			prco[a]++;
		}
		else{
			a++;
		}
	}
	//prime.push_back(n);
	prco[n]++;
}

int main(){
    
    ll n,p;
    cin>>n>>p;
    if(p==1){
        cout<<1<<endl;
        return 0;
    }
    if(n==1){
        cout<<p<<endl;
        return 0;
    }
    prfac(p);
    ll ans=1;
    for(auto x:prco){
        ans*=pow(x.first,int(x.second/n));
    }
    cout<<ans<<endl;
    
}
