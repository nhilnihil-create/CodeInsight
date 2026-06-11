#include<bits/stdc++.h>
using namespace std;
long long n,hp;
long long knife[100005];
long long maxhit;
long long attack;
int main(){
	cin>>n>>hp;
	for(int i=1; i<=n; i++){
		long long a;
		cin>>a>>knife[i];
		maxhit = max(maxhit,a);
	}
	sort(knife+1,knife+n+1);
	for(int i=n-1; i>=1; i--) knife[i]+=knife[i+1];
	attack = hp/maxhit+(hp%maxhit?1:0);
	for(int i=n; i>=1; i--){
		long long adc = n-i+1;
		long long h = max(hp-knife[i],(long long)0);
		adc+=(h/maxhit+(h%maxhit?1:0));
		attack = min(attack,adc);
	}
	cout<<attack;
}