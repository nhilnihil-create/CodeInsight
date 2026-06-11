#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(t>s)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}