#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

	map < pair < string , string > , long long > mapa;
	
	pair < string , string > separate(string a){
		string mali = "", VELIKI = "";
		for(int i = 0; i < a.size(); i++){
			if(a[i] >= 97) mali += a[i];
			else VELIKI = a[i] + VELIKI;
		}
		return make_pair(mali,VELIKI);
	}
	
	pair < string , string > swaping(pair < string , string > a){
		
		string rev_mali = "";
		string rev_veliki = "";
		
		for(int i = 0; i < a.first.size(); i++){
			rev_veliki+=a.first[i] - 32;
		}
		for(int i = 0; i < a.second.size(); i++){
			rev_mali+=a.second[i] + 32;
		}
		return make_pair(rev_mali , rev_veliki);
	}

int main(){

	int n; cin >> n;
	string s; cin >> s;
	string b; b = s.substr(0,n);
	
	for(int i = 0; i < (1<<n); i++){
		b = s.substr(0,n);
		for(int j = 0; j < 20; j++) if(i&(1<<j)) b[j] = s[j] - 32;
		if(mapa.count(separate(b)) == 0) mapa[separate(b)] = 1;	
		else mapa[separate(b)] += 1;	
	//	cout << b << " " << s << endl;
	} 
	
	long long sol = 0;
	for(int i = 0; i < (1<<n); i++){
		b = s.substr(n,n);
		for(int j = 0; j < 20; j++) if(i&(1<<j)) b[j] = s[j+n] - 32;	
		if(mapa.count(swaping(separate(b))) != 0) sol += mapa[swaping(separate(b))];
	//	cout << b << " " << s << endl;
	} cout << sol << endl;





	return 0;
}

