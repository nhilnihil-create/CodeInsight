#include<bits/stdc++.h>
#define ro(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
typedef vector<ll> vi;
ll n,m,x,y;
int main(){
	cin>>n>>m>>x>>y;
    vi no(n),mo(m);
    for(ll &i:no) cin>>i;
    for(ll &i:mo) cin>>i;
    sort(ro(no));
    sort(ro(mo));
    if(*min_element(ro(mo))> *max_element(ro(no))){
    	if(*min_element(ro(mo))>x && *min_element(ro(mo))<=y){
    		cout<<"No War\n";
    	}
    	else{
    		cout<<"War\n";
    	}
    }
    else{
    	cout<<"War\n";
    }
}