#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 
int main() {
	ll n;
	cin>>n;
	n--;
	cout << n<<endl;
	string s;
	cin>>s;
	if(s=="Vacant"){
		return 0;
	}
	ll kiso=0;
	while(true){
		ll sa=(n-kiso)/2;
		ll next=n-sa;
		if(sa==0){
			next=kiso;
		}
		cout << next<<endl;
		string t;
		cin>>t;
		if(t=="Vacant"){
			return 0;
		}
		if(sa%2==0){
		 if(s==t){
			n=next;
		}
		else{
			kiso=next;
		}
		}
		else{
					 if(s!=t){
						s=t;
			n=next;
		}
		else{
			kiso=next;
		}
		}
	}
	// your code goes here
	return 0;
}