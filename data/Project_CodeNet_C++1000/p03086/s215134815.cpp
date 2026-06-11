#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s; cin>>s;
	int ans = -1;
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size()+1; j++){
			int cnt = 0;
			string aux = s.substr(i, j);
			//cout<<aux<<endl;
			for(int k=0; k<aux.size(); k++){
				if(aux[k]=='A'||aux[k]=='C'||aux[k]=='G'||aux[k]=='T')
					cnt++;
				else break;
			}
			if(cnt==aux.size())
				ans = max(ans, cnt);
		}
	}
	cout<<ans<<endl;
}
