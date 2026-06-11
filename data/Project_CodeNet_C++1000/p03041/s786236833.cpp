#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin>> n>> k;
    string s;
    cin>> s;
    while (s[n+1]=='A' || s[n+1]=='B' || s[n+1]=='C'){
        }
    if (s[k-1]=='A'){
        s[k-1]='a';
    }else if(s[k-1]=='B'){
        s[k-1]='b';
        }else if (s[k-1]=='C'){
        s[k-1]='c';
        }
    cout<<s;
    return 0;
}