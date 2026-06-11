#include <iostream>
#include <map>

using namespace std;

int main(){
	int half;
	cin>>half;
	string s;
	cin>>s;

	map<string, int>m;

	for(int i=0;i<(1<<half);i++){
		string r="", b="";
		for(int j=0;j<half;j++){
			if(i & (1<<j)){
				r = r + s[j];
			}
			else
				b = b + s[j];
		}
		m[r + '.' + b]++;
	}

	long long ans=0;

	for(int i=0;i<(1<<half);i++){
		string r="", b="";
		for(int j=0;j<half;j++){
			if(i & (1<<j)){
				r = s[half + j] + r;
			}
			else
				b = s[half + j] + b;
		}
		ans += 1ll*m[b + '.' + r];
	}

	cout<<ans;
}