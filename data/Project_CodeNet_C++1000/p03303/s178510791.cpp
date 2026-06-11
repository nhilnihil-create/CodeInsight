// Don't Lose Hope, Nor Be Sad 

#include <bits/stdc++.h>
using namespace std;

  #define lp(start,finish) for(int i=start; i<finish; i++)
  #define read freopen("input.txt","r",stdin);
  #define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main(){
	//read
	int a,pos=0;
	string s;
	cin >> s;
	cin >> a;
	while(pos<=s.size()-1){
		cout << s[pos];
		pos+=a;
	}
	cout << endl;
	return 0;
}