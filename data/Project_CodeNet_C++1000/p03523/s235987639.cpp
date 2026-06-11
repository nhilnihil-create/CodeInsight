#include<bits/stdc++.h>
using namespace std;

string tar = "AKIHABARA";
string s;

int main(){
	cin >> s;
	bool yes = 1;
	int idx = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == tar[idx]){
			idx++;
		} else if(tar[idx] == 'A' && idx+1<tar.size() && s[i] == tar[idx+1]){
			idx+=2;
		} else {
			yes = 0;
		}
	}
	if(yes && idx >= tar.size()-1) printf("YES\n");
	else printf("NO\n");
  return 0;
}
