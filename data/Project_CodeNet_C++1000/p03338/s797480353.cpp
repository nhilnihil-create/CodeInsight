#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string L="";
	int ans=-1;
	for(int i=0;i<s.size();i++){
		L+=s[i];
		vector<int> a(26,0);
		for(int j=0;j<L.size();j++){
			for(int k=i+1;k<s.size();k++){
				if(L[j]==s[k]){
					a[(int)(L[j]-'a')]=1;
				}
			}
		}
		int cnt=0;
		for(int j=0;j<a.size();j++){
			if(a[j]==1){
				cnt++;
			}
		}
		ans=max(cnt,ans);
	}
	cout << ans << endl;		
				
	return 0;
}
