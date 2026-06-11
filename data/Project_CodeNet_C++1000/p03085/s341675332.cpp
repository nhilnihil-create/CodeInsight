#include<bits/stdc++.h>
using namespace std;
int main(){	
	string s;
  	cin>>s;
  	if(s.at(0) == 'A'){
    	cout<<"T"<<"\n";
    }
       else if(s.at(0) == 'T')
    	{
    	cout<<"A"<<"\n";
    }
    else if(s.at(0) == 'G'){
    	cout<<"C"<<"\n";
    }
       else if(s.at(0) == 'C')
    	{
    	cout<<"G"<<"\n";
    }


	return 0;
}
