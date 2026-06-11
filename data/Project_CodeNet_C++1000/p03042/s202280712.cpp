#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long 
#define dd double
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin>>s;
  string f;
  int x=s/100;
  int y=s%100;
  
  if(x>=1&&x<=12){
  	if(y<=12&&y>=1){
  		f=f+"AMBIGUOUS";
	  }
	else if(y>12){
		f=f+"MMYY";
	} 
	else if(y==0){
		f=f+"MMYY";
	}
  }
  else if(y>=1&&y<=12){
  	if(x<=12&&x>=1){
  		f=f+"AMBIGUOUS";
	  }
	else if(x>12){
		f=f+"YYMM";
	}  
	else if(x==0){
		f=f+"YYMM";
	}
	  
  }
  
  else{
  	f=f+"NA";
  }
	
	  
   cout<<f<<endl; 

  return 0;
}