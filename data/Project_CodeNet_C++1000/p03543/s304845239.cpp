#include <iostream>

using namespace std;

int main()
{
    int i,c;
    string s;
    cin>>s;
    
    if((s[0]==s[1]&& s[1]==s[2])||(s[1]==s[2]&& s[2]==s[3]))
    cout<<"Yes";
    else
    cout<<"No";
    
    return 0;
}
