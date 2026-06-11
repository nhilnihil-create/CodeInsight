#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
      
        string s;
        cin>>s;
        int n=(int)s.length();
        if(n<26)
        {
			for(char c='a';c<='z';c++)
			{
				if(s.find(c)==string::npos)
				{
					cout<<s<<c<<"\n";
					return 0;
				}
			}
		}
		else
		{
			    for (int i = n - 2; i >= 0; i--) {
          if (s[i] < s[i + 1]) {
        char best = s[i + 1];
        for (int j = i + 1; j < n; j++) {
          if (s[j] > s[i]) {
            best = min(best, s[j]);
          }
        }
        s[i] = best;
        s = s.substr(0, i + 1);
        cout << s << '\n';
        return 0;
      }
    }
    cout << -1 << '\n';
    }
    return 0;
		
			
	    
  }
			
		