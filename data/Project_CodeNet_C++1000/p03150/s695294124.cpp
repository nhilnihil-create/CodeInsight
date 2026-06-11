#include<bits/stdc++.h>
using namespace std;
int main(){
	
	string s;cin>>s;

	int n = s.length();

	string target = "keyence";

	if(target==s){
		puts("YES");
		return 0;
	}

	for(int i=0;i<n;i++){

		for( int j=i;j<n;j++ ){

			string temp = "";

			for( int k=0;k<n;k++ ){

				if( i<=k && k<=j )continue;
				temp+=s[k];

			}

			if( temp==target ){
				puts("YES");
				return 0;
			}

		}

	}
	puts("NO");
	return 0;

	/*
	1. Check for output format
	2. CHeck for corner cases
	3. Compile and run given TC first
	*/

}