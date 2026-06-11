#include<iostream>
#include <string>
using namespace std;
int main()
{
	string s, t, r;
	cin >> s >> t;
	int lens = s.size();
    int lent = t.size();
    for(int i = 0; i < lens; i++)
    {
        if(s[i] == '?' || s[i] == t[0])
        {
            string tmp = s;
            for(int j = 0; j < i; j++) if(tmp[j] == '?') tmp[j] ='a';
            bool mark = false;
            for(int j = 0; j < lent; j++)
            {
                if(tmp[i+j]!= '?' && tmp[i+j] != t[j]) 
                    break;
                tmp[i+j] = t[j];
                if(j == lent - 1) mark = true;
            }
            if(mark)
            {
                for(int j = i + lent; j < lens; j++) if(tmp[j] == '?') tmp[j] = 'a';
                r=tmp;
            }
        }
    }
    if(r.size() == 0) cout << "UNRESTORABLE" << endl;
    else cout << r << endl;
    return 0;
}