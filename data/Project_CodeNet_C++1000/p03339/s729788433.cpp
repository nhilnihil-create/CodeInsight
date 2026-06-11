#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;

	vector<int> ruisekiW(n+1,0);
	vector<int> ruisekiE(n+1,0);

	for(int i=1;i<=n;i++){
		ruisekiW.at(i)=ruisekiW.at(i-1);
		ruisekiE.at(i)=ruisekiE.at(i-1);

		if(s.at(i-1)=='W') ruisekiW.at(i)++;
		else ruisekiE.at(i)++;
	}

	int ans=4*pow(10,5);

	for(int i=0;i<n;i++){
		int hoge=ruisekiW.at(i) + ruisekiE.at(n)-ruisekiE.at(i+1);
		ans=min(ans,hoge);
	}

	cout<<ans<<endl;

    return 0;
}
