#include<bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    cin>>str;
    int n;
    cin>>n;
    for(int i=0;i<str.size();i+=n) printf("%c",str[i]);
    cout<<endl;

    return 0;
}