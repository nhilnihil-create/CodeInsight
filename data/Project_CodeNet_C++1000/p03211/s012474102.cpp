#include <bits/stdc++.h>

using namespace std;

bool StringToInt(string s, int &data)
{
	data=0;
	int sign=1;
	for(int i=0;i<s.length();i++){
		if(i==0 && s[i]=='-'){
            sign=-1;
            continue;
        }
		if('0'<=s[i] && s[i]<='9'){
			data*=10;
			data+=sign*(s[i]-'0');
		}
		else return false;
	}
	return true;
}

int main()
{
    string s;
    cin >> s;

    int ans=1e9;
    for(int i=0;i<s.length()-2;i++){
        int x;
        StringToInt(s.substr(i,3),x);
        ans=min(ans,abs(x-753));
    }
    
    cout << ans << endl;
}