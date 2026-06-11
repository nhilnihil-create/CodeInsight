#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//vector<string> w;
	int i;
	bool ok = true;
	map<string, int> wi;
	string s;
	cin >> s;
	wi[s]++;
	int len;
	len = s.length()-1;
	char last = s[len];
	for(i=1; i<n; i++){
		cin >> s;
		wi[s]++;
		//w.push_back(s);
		len = s.length()-1;
		if(last!=s[0]) ok = false;
		else last = s[len];
		//cout << ok << endl;
	}
	if(!ok){
		cout << "No\n";
	}
	else{
		for(auto it = wi.begin(); it!=wi.end(); ++it){
			//cout << it->second << endl;
			if(it->second > 1){
				ok = false;
				break;
			}
		}
		if(!ok) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
	
