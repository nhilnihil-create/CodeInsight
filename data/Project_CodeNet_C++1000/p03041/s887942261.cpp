#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);
       cin.tie(0);
  int n ,k;
  string s;
  cin>>n>>k>>s;
  if(s.at(k - 1) == 'A')
  	 s.at(k - 1) ='a'; 
  	 if(s.at(k - 1) == 'B')
  	 	 s.at(k - 1) = 'b';
  	 	 if(s.at(k - 1) == 'C')
  	 	 	 s.at(k - 1) = 'c';
  	 	 	cout<<s<<endl;
  	 	 	return 0;
  	 	 }    