#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll mx=1e5;
//bool prime[100009];
//void seive()
//{
//    prime[1]=true;
//    for(int i=2;i*i<=mx;i++){
//        if(prime[i]==false){
//            for(int j=i*i;j<=mx;j+=i) prime[j]=true;
//        }
//    }
//}
int main(){
	ll n;
	cin>>n;
	vector<ll>v;
	for(ll i=1;i*1ll*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(i*i!=n)v.push_back(n/i);
        }
	}
	sort(v.begin(),v.end());
	ll sum=0;
	for(auto x:v){
        ll p=n/x-1;
        if(p!=0 && (n/p==n%p))sum+=p;
	}
	cout<<sum<<endl;
}
