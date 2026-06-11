#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int x,y;
	cin >> x >> y;

	int n = s.size();

	vector<int> v;
	vector<int> h;

	bool hori = true;
	int cnt = 0;
	rep(i,n){
		char c = s[i];
		if(c == 'F') cnt++;
		else{
			if(hori) h.push_back(cnt);
			else v.push_back(cnt);
			hori = !hori;
			cnt = 0;
		}
	}

	if(cnt != 0){
		if(hori) h.push_back(cnt);
			else v.push_back(cnt);
	}

	int hlen = h.size();
	bool dph[hlen+1][16000];
	rep(i,hlen+1) rep(j,16000) dph[i][j] = false;
	dph[0][8000] = true;

	if(s[0] == 'F'){
		dph[1][8000+h[0]] = true;
	}else{
		dph[1][8000+h[0]] = true;
		dph[1][8000-h[0]] = true;
	}

	FOR(i,1,hlen){
		rep(j,16000){
			dph[i+1][j] |= dph[i+1][j];
			if(j+h[i] < 16000) dph[i+1][j] |= dph[i][j+h[i]];
			if(0 <= j-h[i]) dph[i+1][j] |= dph[i][j-h[i]];

		}
	}


	int vlen = v.size();
	bool dpv[vlen+1][16000];
	rep(i,vlen+1) rep(j,16000) dpv[i][j] = false;
	dpv[0][8000] = true;

	rep(i,vlen){
		rep(j,16000){
			dpv[i+1][j] |= dpv[i+1][j];
			if(j+v[i] < 16000) dpv[i+1][j] |= dpv[i][j+v[i]];
			if(0 <= j-v[i]) dpv[i+1][j] |= dpv[i][j-v[i]];

		}
	}

	cout << (dph[hlen][x+8000] && dpv[vlen][y+8000] ? "Yes" : "No") << endl;
}