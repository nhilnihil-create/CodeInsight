#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
	set<int>s;
	int a;
	for(int i=0;i<4;i++){
		cin>>a;
		if(a==1||a==9||a==7||a==4){
			s.insert(a);
		}
	}
	if(s.size()==4){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
		return 0;
}

