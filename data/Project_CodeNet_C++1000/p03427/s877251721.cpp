#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int sum1=0,sum2=0;
    sum1+=(s[0]-'0')-1;
    sum1+=(s.length()-1)*9;
    for(int i=0;i<s.length();i++)
    {
        sum2+=(s[i]-'0');
    }
    cout<<max(sum1,sum2)<<endl;
    return 0;
}
