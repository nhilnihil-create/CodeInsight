#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    string key="keyence";
    int lnth=s.length();
    
    
    for(int i=0;i<=7;i++){
    	bool ans=true;
    	int ind=0;
    	for(int j=0;j<i;j++){
    		if(key[ind++]!=s[j]){
    			ans=false;
    			//cout<<i<<" "<<j<<" "<<key[ind-1]<<endl;
    			break;
    			
    		}
    	}
    	for(int j=i+lnth-7;j<lnth;j++){
    		if(key[ind++]!=s[j]){
    			ans=false;
    			//cout<<i<<" "<<j<<" "<<key[ind-1]<<endl;
    			break;
    			
    		}
    	}
    	if(ans){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
  	return 0;
}