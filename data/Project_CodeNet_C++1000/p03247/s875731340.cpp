#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 1010
ll x[N],y[N],n;
int NOE(){
    cout<<-1<<endl;
    return 0;
}
int main(){
    cin>>n;
    set<bool> sl,sr;
    lol(i,n){
	ll X,Y;cin>>X>>Y;
	x[i]=X+Y;
	y[i]=X-Y;
	sl.insert(x[i]&1);
	sr.insert(y[i]&1);
    }
    
    if(sl.size()>1||sr.size()>1)return NOE();
    if(*sl.begin()!=*sr.begin())return NOE();
    
    vector<ll> d;
    if(*sl.begin()==0)d.push_back(1);
    for(ll i=0;i<32;i++)d.push_back(1LL<<i);
    cout<<d.size()<<endl;
    lol(i,d.size()){
	if(i)cout<<" ";
	cout<<d[i];
    }cout<<endl;
    
    ll sum=0; for(auto z:d)sum+=z;
    lol(i,n){
	ll X=sum-x[i],Y=sum-y[i];
	for(ll j=0;j<d.size();j++){
	    ll z=d[j]*2,res=0;
	    if(z&X)X-=z,res++;
	    if(z&Y)Y-=z,res+=2;
	    string ans="RDUL";
	    cout<<ans[res];
	}cout<<endl;
    }
    return 0;
}
