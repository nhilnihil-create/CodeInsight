
#include <bits/stdc++.h> 
using namespace std; 


int main() 
{ 

string s,s1;
cin>>s>>s1;
		char  key[s.length()+1] ;
		 strcpy(key, s.c_str());
		 char flagment[s1.length()+1] ;
		 strcpy(flagment, s1.c_str());
		 
		 int n = s.length()-s1.length();
		
		for ( int i=n; i>= 0 ;i--) { //Search from behind S
			
			bool temp = true ;
			 for ( int j= 0 ;j<s1.length(); j++) {
				 if (key[i+j]!= '?' && key[i+j]!=flagment[j]) {
					temp = false ;
					 break ;
				}
			}
			
			if (temp == true ){
				 for ( int j= 0 ;j<s1.length(); j++) {
					key[i+j] = flagment[j];
				}
				for ( int j= 0 ;j<s.length(); j++) {
				
					cout<<(key[j]== '?' ? 'a' :key[j]);
				}

				return 0;
			}
			
		}
		
	cout<< "UNRESTORABLE"<<endl;
		
}