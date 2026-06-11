	#include <bits/stdc++.h>
	using namespace std;
	int main(int argc, char const *argv[])
	{
		     //  #ifndef ONLINE_JUDGE
	      //  // for getting input from input.txt
	      //  freopen("input.txt", "r", stdin);
	      //  // for writing output to output.txt
	      //  freopen("output.txt", "w", stdout);
	      // #endif
		string s1,s2;
		cin>>s1>>s2;
		if(s1.at(0) == s2.at(2)){
			if(s1.at(1) == s2.at(1)){
				if(s1.at(2) == s2.at(0)){
					cout<<"YES"<<"\n";
					return 0;
				}
			}
		}
		cout<<"NO"<<"\n";
		return 0;
	}