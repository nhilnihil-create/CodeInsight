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

const long long INF_L = 1e17+7;
const long long INF_I = 1e9+7;
const long long MOD = 1e9+7;
const double EPS = 1e-8;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s,t;
	cin >> s >> t;
		
	for(int i=s.size()-t.size();i>=0;i--){
		for(int j=0;j<t.size();j++){
			if(s[i+j]!='?' && s[i+j]!=t[j]){
				break;
			}else if(s[i+j]==t[j] || s[i+j]=='?'){
				bool ok=true;
				for(int k=0;k<t.size();k++){
					if(s[i+k]=='?' || s[i+k]==t[k]){
						continue;
					}else if(s[i+k]!=t[k]){
						ok=false;
					   break;
					}
				}
				if(ok){
					for(int k=0;k<t.size();k++){
						s[i+k]=t[k];
					}
					for(int i=0;i<s.size();i++){
						if(s[i]=='?'){
							s[i]='a';
						}
					}
					cout << s << endl;
					return 0;
				}
			}
		}
	}
	cout << "UNRESTORABLE" << endl;
	return 0;
}
