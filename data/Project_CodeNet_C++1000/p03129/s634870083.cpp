//cnt0 += s[i] == '0';
#include <bits/stdc++.h>
# define ll long long 
# define all(vc) vc.begin(),vc.end()
# define str string 
# define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
stack <char> stk;
vector <int> vc;
vector <char> A;
set <ll> B;
ll a,b,c,d,e,f,g,h,cnt,bnt,p,sum;
str s,cal;
map <char,ll> mp;
ll arr[1000][6];
char ch;
bool ok=true;
int main(){
	speed;
	cin>>a>>b;
	if(a%2==0){
		if(a/2>=b) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else {
		if((a/2)+1>=b) cout<<"YES\n";
		else cout<<"NO\n";
	}
	time;
	return 0;
}