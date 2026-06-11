#include <iostream>
using namespace std;

int main() {
	int h,w,n;
	cin >> h >> w >> n;
	int s1,s2;
	cin >> s1 >> s2;
	string s,t;
	cin >> s >> t;
	int l=0,r=0,u=0,d=0;
	int L=s2-1,R=w-s2,U=s1-1,D=h-s1;
	for(int i=0;i<n;i++){
		if(s[i]=='L'){
			l++;
		}
		else if(s[i]=='R'){
			r++;
		}
		else if(s[i]=='U'){
			u++;
		}
		else if(s[i]=='D'){
			d++;
		}
		if(l>L || r>R || u>U || d>D){
			cout << "NO";
			return 0;
		}
		if(t[i]=='L'){
			r--;
			r=max(r,-L);
		}
		else if(t[i]=='R'){
			l--;
			l=max(l,-R);
		}
		else if(t[i]=='U'){
			d--;
			d=max(d,-U);
		}
		else if(t[i]=='D'){
			u--;
			u=max(u,-D);
		}
		
	}
	cout << "YES";
	
	// your code goes here
	return 0;
}