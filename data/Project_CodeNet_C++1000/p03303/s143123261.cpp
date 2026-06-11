#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w=0;string s;
    cin>>s;
    cin>>w;
    for(int i=0;i<s.length();i+=w)
    	cout<<s[i];
    cout<<endl;
}