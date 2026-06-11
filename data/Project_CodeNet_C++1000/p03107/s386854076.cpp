#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define N 10000
ll tra[100006],tra1[100006];

int main()
{
    string s;
    cin>>s;
    ll one=0,zero=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
            one++;
        else
            zero++;
    }
    cout<<(min(one,zero)*2)<<endl;



}