//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}


ll a[612345],pre[612345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,x;
    ll i;
    cin>>n>>x;
    fd(i,n-1,0){
    	cin>>a[i];
    }
    pre[0]=a[0];
    ll ans,j,mini=inf,val;
    mini*=inf;
    ll iinf=inf;
    iinf*=inf;
    f(i,1,2*n+100){
    	pre[i]=pre[i-1]+a[i];
    }
    f(i,1,n+1){
    	ans=5*(pre[i-1])+x*i;
    	//cout<<pre[i-1]<<"dsdsa"<<endl;
    	val=5;
    	for(j=i;j<n;j+=i){
    		if(iinf/val<pre[j+i-1]-pre[j-1])
    			ans=iinf;
    		else
    			ans+=val*(pre[j+i-1]-pre[j-1]);
    		if(ans>iinf){
    			ans=iinf;
    		}
    		val+=2;
    	}
    	//cout<<i<<" "<<ans<<endl;
    	mini=min(mini,ans);
    }
    cout<<mini+x*n<<endl;
    return 0;   
}

