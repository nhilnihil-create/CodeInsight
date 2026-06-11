#include <bits/stdc++.h>
using namespace std;

int N,A,B,C,D; string s;

int main(){
	cin>>N>>A>>B>>C>>D>>s; bool pos=true;
	for(int i=A; i<C-1; i++){
		if(s[i]=='#'&&s[i+1]=='#')pos=false;
	}
	for(int i=B; i<D-1; i++){
		if(s[i]=='#'&&s[i+1]=='#')pos=false;
	}
	if(C>D){
		bool jump=false;
		for(int i=B-2; i<D-1; i++){
			if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.')jump=true;
		}
		pos=pos&&jump;
	}
	cout<<(pos ? "Yes" : "No")<<'\n';
}