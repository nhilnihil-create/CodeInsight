using namespace std;
#include <bits/stdc++.h>

int main()
{
    int a=700;
    string s;cin>>s;
    if(s[0]=='o'){a+=100;}
    if(s[1]=='o'){a+=100;}
    if(s[2]=='o'){a+=100;}
    std::cout << a << std::endl;
    return 0;
}