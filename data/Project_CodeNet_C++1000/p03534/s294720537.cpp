#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<complex>
#define lol(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;

int main(){
	string s;
	cin>>s;
	int cnt[3]={0};
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
	}
	int a=-1;
	a=max(a,abs(cnt[0]-cnt[1]));
	a=max(a,abs(cnt[2]-cnt[1]));
	a=max(a,abs(cnt[0]-cnt[2]));
	if(a<=1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
