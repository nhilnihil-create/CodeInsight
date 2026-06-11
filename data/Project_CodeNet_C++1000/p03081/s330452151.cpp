#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;
	cin>>n>>q;
	string s;
	cin>>s;
	vector<char> t, d;
	for(int i = 0; i < q; i++){
		char tt, td;
		cin>>tt>>td;
		t.push_back(tt);
		d.push_back(td);
	}
	int ans = n;
	int l = -1, r = n;
	while(r - l > 1){
		int mid = (r + l) / 2;
		bool fl = false;
		int pos = mid;
		for(int i = 0; i < q; i++){
			if( 0 <= pos && pos < n && t[i] == s[pos]){
				if(d[i] == 'L')
                    pos--;
				else pos++;
			}
			if( pos == -1 )
                fl = true;
		}
		if(fl){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	ans -= r;
	l = -1, r = n;
	while(r - l > 1){
		int mid = (r + l) / 2;
		bool fl = false;
		int pos = mid;
		for(int i = 0; i < q; i++){
			if( 0 <= pos && pos < n && t[i] == s[pos]){
				if(d[i] == 'L')
                    pos--;
				else
                    pos++;
			}
			if(pos == n)
                fl = true;
		}
		if(fl){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	ans -= (n - r);
	cout<<ans<<endl;
	return 0;
}
