#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	int ans;
	vector<int> p(n);
	for (int i = 1; i < n; ++i)
	{
		if(s.at(i)=='E'){
			p.at(0)++;
		}
	}
  ans = p.at(0);
	for (int i = 0; i < n-1; ++i)
	{
		if(s.at(i)=='E'){
			if(s.at(i+1)=='E'){
				p.at(i+1)=p.at(i)-1;
			}
			else{
				p.at(i+1)=p.at(i);
			}
		}
		else{
			if(s.at(i+1)=='W'){
				p.at(i+1)=p.at(i)+1;
			}
			else{
				p.at(i+1)=p.at(i);
			}
		}
		ans = min(ans,p.at(i+1));
	}

cout << ans << endl;
	}