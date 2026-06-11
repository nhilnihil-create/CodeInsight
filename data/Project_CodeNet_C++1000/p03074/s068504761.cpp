#include<bits/stdc++.h>
#define se second
#define fi first
#define pb push_back
#define cn cout<<"\n"
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)
#define all(v) v.begin(), v.endd()
#define allr(v) v.rbegin(), v.rend()

#define _ ios::sync_with_stdio(0); cin.tie(0);

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define vll vector<ll>
#define flush fflush(stdout)

const int INF = 1e8;
const ll MOD = 1e9 + 7;

using namespace std;

int main(){
	_

	int t = 1;

	int n, k;
	string s;
	cin>>n>>k>>s; s = s + '2';
	vi last;
	rep(i, 0, n + 1)
		if(i - 1 >= 0 && s[i] != '0' && s[i - 1] == '0')
			last.pb(i - 1);

/*	rep(i, 0, last.size())
		cout<<last[i]<<"\n";*/

	int ans = 0, pre = 0, cur = 0;

	int i = 0, j = 0;
	while(i < n){

		if(s[i] == '1') cur++, i++;
		else{
			if(k == 0){
				//cout<<"ib "<<i<<" "<<cur; cn;
				while(pre <= last[j])
					cur--, pre++;
				j++, k++;
			}

			while(s[i] == '0' && i < n)
				cur++, i++;
			k--;
		}

		ans = max(ans, cur);
	}

	cout<<ans; cn;

	return 0;
}

/*

14 2
11101010110011

5 1
00010

*/