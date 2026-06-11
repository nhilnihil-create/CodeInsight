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

    string y=s.substr(0,4);
    string m=s.substr(5,2);
    string d=s.substr(8,2);

    int yy;
    int mm;
    int dd;
    StringToInt(y,yy);
    StringToInt(m,mm);
    StringToInt(d,dd);

    if(yy<=2019){
        if(mm<=4){
            if(dd<=30) cout << "Heisei" << endl;
            else cout << "TBD" << endl;
        }
        else cout << "TBD" << endl;
    }
    else cout << "TBD" << endl;
}