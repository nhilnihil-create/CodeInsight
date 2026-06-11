#include <bits/stdc++.h>
using namespace std;
vector <string> ve;
int main(){
    string s0="AKIHABARA";
    string s;
    cin>>s;

    int l=0;
    int r=0;
    bool flag=0;

    if (s.length()>s0.length())
    {
        puts("NO");
        exit(0);
    }
    while (l<s0.length() && r<s.length())
    {

        if (s0[l]==s[r])
        {
            l++;
            r++;
        }
        else
        {
            if (s0[l]!='A')
            {
                puts("NO");
                exit(0);
            }
            l++;
        }
    }
    if (r<s.length())
    {
        puts("NO");
    }
    else
    {
        if (l<(s0.length()-1)) puts("NO");
        else puts("YES");
    }
}
