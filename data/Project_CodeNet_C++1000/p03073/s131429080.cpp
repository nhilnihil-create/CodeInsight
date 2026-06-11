#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	int bwbw=0,wbwb=0;
	for(int i=0;i<n;i++){
		if(i%2&&s[i]=='0')bwbw++;
		if(i%2==0&&s[i]=='1')bwbw++;
		if(i%2&&s[i]=='1')wbwb++;
		if(i%2==0&&s[i]=='0')wbwb++;
	}
	cout<<min(bwbw,wbwb);
    return 0;
}
