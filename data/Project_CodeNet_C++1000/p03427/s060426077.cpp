#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
using ll = long long;
using P = pair<int,int>;

int main(){
	string n;
	cin>>n;
	string s=n.substr(0,1);
	bool a=true;
	for(int i=1;i<n.size();i++){
		a=a&&n[i]=='9';
	}
  	if((int)n.size()==1){
      puts(n);
      return 0;
    }
      
	if(a){
		puts(9*(int)n.size()-9+stoi(s));
		return 0;
	}
	if(stoi(s)==1)puts(9*(int)(n.size()-1));
	else puts(9*(int)(n.size()-1)+stoi(s)-1);
}
