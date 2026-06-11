#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int s;
  	cin>>s;
  
	int mae=s/100;
    int usiro=s%100;
  
  	bool mmyy=true;
  	bool yymm=true;
  
  if(mae<1||12<mae){
  	mmyy=false;
  }
  
  if(usiro<1||12<usiro){
  	yymm=false;
  }
  


if(yymm&&mmyy){cout<<"AMBIGUOUS"<<endl;}
else if(yymm){cout<<"YYMM"<<endl;}
else if(mmyy){cout<<"MMYY"<<endl;}
else {cout<<"NA"<<endl;}
}