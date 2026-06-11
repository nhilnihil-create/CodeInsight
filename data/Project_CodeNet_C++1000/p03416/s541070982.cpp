#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, i;
	cin >> a >> b;
	string s;
	int j, k, count = 0;
	bool ok;
	for(i=a; i<=b; i++){
		s = to_string(i);
		j = 0;
		k = s.length()-1;
		ok = true;
		while(j<k){
			if(s[j]!=s[k]){
				ok = false;
				break;
			}
			j++;
			k--;
		}
		count = (ok) ? count+1 : count;
	}
	cout << count << endl;
	return 0;
}
