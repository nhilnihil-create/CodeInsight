#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int msum=0;
	set<char> g(s.begin(),s.end());
	for(int i =0;i<n;i++){
		string t1= s.substr(0,i);
		string t2= s.substr(i,n-i);
		//cout << s.substr(0,i) << " " << s.substr(i,n-i) << endl;
		set<char> s1(t1.begin(),t1.end());
		set<char> s2(t2.begin(),t2.end());
		//cout << (int)s1.size() << " " << (int) s2.size() << endl;

		msum = max(msum,((int)s1.size()+(int)s2.size()-(int)g.size()));
	}
	cout << msum;
				
	
			
     
}
