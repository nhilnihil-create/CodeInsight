#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    //cout << s << endl << t << endl;
    int i = 0;
    while(i < min((int)s.length(),(int)t.length())){
		if(s[i]<t[i]){cout << "Yes"; return 0;}
		if(s[i]>t[i]){cout << "No"; return 0;}
		i++;
		}
	
	if(i < (int)s.length()) cout << "No";
	else if(i==(int)s.length() && i==(int) t.length()) cout << "No";
	else cout << "Yes";
		
}
