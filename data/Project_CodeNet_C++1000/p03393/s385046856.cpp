#include<bits/stdc++.h>
#include<numeric>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	map<char,int> smap;
	rep(i,S.size()){
		smap[S[i]]++;
	}

	if(smap.size() != 26){
		char ch = 'a';
		while(1){
			if(!smap.count(ch)){
				S.push_back(ch);
				cout << S << endl;
				return 0;
			}
			else{
				ch++;
			}
		}
	}
	else{
		map<char,int> yuni;
		yuni[S[S.size()-1]]++;
		for(int index = S.size() - 2; index >= 0; index-- ){
			for(auto p: yuni ){
				if(p.first > S[index]){
					rep(j,index){
						cout << S[j];
					}
					cout << p.first << endl;
					return 0;
				}
				else{
					yuni[S[index]]++;
				}
			}
		}
	}


	cout << "-1" << endl;
	
	return 0;
}