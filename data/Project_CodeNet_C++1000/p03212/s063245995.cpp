#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> pi;
bool check(string&a){
	bool three = false;
	bool five = false;
	bool seven = false;
	
	for(int i=0; a[i]; i++){
		if(a[i]=='3') three = true;
		if(a[i]=='5') five = true;
		if(a[i]=='7') seven = true;
	}
	if(three && five && seven) return true;
	return false; 
}
bool comp(string&a, int n){
	long long number = 0;
	long long unit = 1;
	for(int i=a.length()-1; i>=0; i--){
		long long num = (int)(a[i]-'0');
		number+=num*unit;
		unit*=10;
	}
	if(number<=n) return true;
	else return false; 
}
int main(){
	int n;
	cin>>n;
	int t = n;
	int len = 0;
	while(t){
		len++;
		t/=10;
	}
	queue<pi>q;
	string s = "3";
	q.push(pi(s,1));
	s = "5";
	q.push(pi(s,1));
	s = "7";
	q.push(pi(s,1));
	int ret = 0;
	while(!q.empty()){
		string curr = q.front().first;
		int d = q.front().second;
		q.pop();
		if(d>len) continue;
		if(check(curr) && comp(curr,n)){
			ret++;
		}
		curr.push_back('3');
		q.push(pi(curr,d+1));
		curr.erase(curr.length()-1,1);
		
		curr.push_back('5');
		q.push(pi(curr,d+1));
		curr.erase(curr.length()-1,1);
		
		curr.push_back('7');
		q.push(pi(curr,d+1));
	}
	cout<<ret;
}