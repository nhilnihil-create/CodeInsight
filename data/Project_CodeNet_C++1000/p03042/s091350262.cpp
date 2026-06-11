#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n; cin>>n;
	int x = n/100;
	int y = n%100;
	if(x>=1 && x<=12){
		if(y>=1 && y<=12){
			cout<<"AMBIGUOUS"<<endl;
		}else{
			cout<<"MMYY"<<endl;
		}
	}else{
		if(y>=1 && y<=12){
			cout<<"YYMM"<<endl;
		}else{
			cout<<"NA"<<endl;
		}
	}
}
