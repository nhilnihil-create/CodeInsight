#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
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
ll n,k;
ll cnt[40];
ll fu(ll bit){
	if(bit<0) return 0;
	ll tmp1=0;
	ll tmp2=0;
	if(!((ll)k&((ll)1<<bit))) {
		tmp1+=((ll)1<<bit)*cnt[bit];
		tmp1+=fu(bit-1);
	}
	else{

		FOR(i,0,bit-1){
			tmp1+=((ll)1<<i)*max(cnt[i],n-cnt[i]);
		}
		tmp1+=((ll)1<<bit)*(cnt[bit]);
		tmp2+=((ll)1<<bit)*(n-cnt[bit]);
		tmp2+=fu(bit-1);
	}
	//dbg3(bit,tmp1,tmp2);
	return max(tmp1,tmp2);

}


int main(){

cin>>n>>k;
std::vector<ll> a(n);
fo(i,n) cin>>a[i];

fo(i,40) cnt[i]=0;
fo(i,n){
	fo(j,40){
		if(((ll)1<<j&a[i])) cnt[j]++;


	}
}

ll ans=fu(39);
//dbg(cnt[0]);
cout<<ans<<endl;


}


