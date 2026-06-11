#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;
ll k,l;

void mostFrequent(ll arr[],ll n){ 

    unordered_map<ll, ll> hash; 
   
	for (int i = 0; i < n; i++)
        hash[arr[i]]++;
    
    ll max_count = 0, res = -1; 
    for (auto i : hash) {
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        }
    } 
    k=res;
    l=max_count;
} 

ll fi,fix,si,six;

void mostFrequent2(ll arr[],ll n, ll mx){ 

    unordered_map<ll, ll> hash; 
   
	for (int i = 0; i < n; i++){
		if(arr[i]!=mx)
        	hash[arr[i]]++;
	}
    
    ll max_count = 0, res = -1; 
    for (auto i : hash) {
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        }
    } 
    k=res;
    l=max_count; 
    
} 


ll idx,f,fx,s,sx,idx1;

int main(){
	ll n;
	cin>>n;
	ll even[n/2],odd[n/2];
	for(ll i=0; i<n; i++){
		ll a;
		cin>>a;
		if(i%2==0) odd[idx++]=a;
		else even[idx1++]=a;
	}
	sort(odd,odd+idx);
	sort(even,even+idx1);
	
	mostFrequent(odd,n/2);
	f=k;
	fx=l;
	mostFrequent(even,n/2);
	s=k;
	sx=l;
	
	mostFrequent2(odd,n/2,f);
	fi=k;
	fix=l;
	mostFrequent2(even,n/2,s);
	si=k;
	six=l;
	
	if(f!=s){
		cout<<((n/2)-fx)+((n/2)-sx);
	}
	else{
		cout<<((n/2)-max(fix,six))+((n/2)-fx);
	}
}
