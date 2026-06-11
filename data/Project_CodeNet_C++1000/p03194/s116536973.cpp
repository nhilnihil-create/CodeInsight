// #include<iostream>
// using namespace std;
// #define ll long long
//
// int main(){
//   ll n,p,ret,ans=0;cin>>n>>p;
//   for(int i=0;i<n*n;i++){
//     ll temp=p,cnt=0;
//     while(temp%i==0){
//       temp=temp/i;
//       cnt++;
//     }
//     ret=max(ans,cnt);
//   }
//   if(ret>n)ans=ret;
//   else ans=1;
//   cout<<ans<<endl;
// }

#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> P;

map<llong, llong> soinsuBunkai(llong n){
	map<llong, llong> ret;
	while(n % 2 == 0){
		ret[2]++;
		n /= 2;
	}
	for(llong i = 3; i*i <= n; i += 2){
		while(n%i == 0){
			ret[i]++;
			n /= i;
		}
	}
	ret[n]++;

	return ret;
}


int main(){
	llong N, p;
	cin >> N >> p;
	auto soinsu = soinsuBunkai(p);
	llong ans = 1;
	for(auto it = soinsu.begin(); it != soinsu.end(); it++){
		cerr << it->first << " " << it->second << endl;
		for(int i = 0; i < it->second/N; i++)
			ans *= it->first;
	}

	cout << ans << endl;

	return 0;
}
