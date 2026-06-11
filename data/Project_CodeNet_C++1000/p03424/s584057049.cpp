#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    char ch;
    set<char>s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ch;
        s.insert(ch);
    }
    cout<<(s.size()==3?"Three":"Four")<<endl;
}
