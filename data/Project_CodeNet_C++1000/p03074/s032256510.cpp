#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
//124D Handstand
int main() {
	int n,k,ren=1,ans=0,l;
	string s;
	cin>>n>>k>>s;
	vector<int>pat;
	if(s[0]=='0')pat.push_back(0);
	for(int i=1;i<s.size();i++){
	    if(s[i]==s[i-1])ren++;
	    else{
	        pat.push_back(ren);
	        ren=1;
	    }
	}
	pat.push_back(ren);
	if(s[s.size()-1]=='0')pat.push_back(0);
	l=pat.size();//odd
	//rep(i,pat.size())cout<<pat[i];
	vector<int>wa(l);
	wa[0]=pat[0];
	rep(i,l-1)wa[i+1]=wa[i]+pat[i+1];
	if(k>=l/2){
	    cout<<wa[l-1];
	    return 0;
	}
	else{
	    ans=wa[2*k];
	    for(int i=1;i*2+k*2<l;i++){
	        ans=max(ans,wa[i*2+k*2]-wa[i*2-1]);
	    }
	}
	cout<<ans;
	return 0;
}
