#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
long long int mod=1e9+7;
bool debug=false;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	int head=0,tail=n-1;
	int hm;
	cout<<0<<endl;
	string s;
	cin>>s;
	if(s[0]=='V')return 0;
	else if(s[0]=='M') hm=0;
	else hm=1;
	while(1){
		//cout<<"hm="<<hm<<"head="<<head<<"tail="<<tail<<endl;
		cout<<(head+tail+1)/2<<endl;
		cin>>s;
		if(s[0]=='V')return 0;
		else if(s[0]=='M') {
			if(((head+tail+1)/2-head+hm)%2==0){
				hm=0;
				head=(head+tail+1)/2;
			}else{
				tail=(head+tail+1)/2-1;
			}
		}else{
			if(((head+tail+1)/2-head+hm)%2==1){
				hm=1;
				head=(head+tail+1)/2;
			}else{
				tail=(head+tail+1)/2-1;
			}
		}
	}


	return 0;
}