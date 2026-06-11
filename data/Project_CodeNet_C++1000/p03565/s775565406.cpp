#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>


int main()
{
    std::string s, t;
    std::cin >> s >> t;

    std::string sc(s);


    if(s.find(t) == std::string::npos) {
    for(int i = s.size() - t.size(); i >= 0; i--) {
        bool f = true;
        int ip = i;
        for(int j = 0; j < t.size(); j++) {
           

            if(s[ip] != t[j] && s[ip] != '?') {
               
                f = false;
                break;
            }

            ip++;
        }

        if(f) {

            int ipp = i;
            
            for(int j = 0; j < t.size(); j++) {
                s[ipp++]= t[j];
            }
            
            break;
        }


    }
    }

    std::string ans;

    if (sc == s && s.find(t) == std::string::npos)
    {
        ans = "UNRESTORABLE";
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                s[i] = 'a';
            }
        }

        ans = s;
    }

    std::cout << ans << std::endl;
}

    