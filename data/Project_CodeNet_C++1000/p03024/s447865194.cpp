#include<bits/stdc++.h>

using namespace std;

 int main()
 {
    string s;
    cin>>s;
    int o=8-count(s.begin(),s.end(),'o');
    int x=15-s.size();
    if(x>=o)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
return 0;
 }
