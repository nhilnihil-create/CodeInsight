#include <bits/stdc++.h>
#define fio     ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pi      3.14159265
#define ll      long long
#define repe    ll tc,cas=0;cin>>tc;while(tc--)
#define op      freopen("output.txt", "w", stdout);

#define maxn 10000010
using namespace std;

int main()
{
    fio;
    char s;
    cin>>s;

    if(s=='A')
        cout<<'T'<<endl;
    else if(s=='T')
        cout<<'A'<<endl;
    else if(s=='G')
        cout<<'C'<<endl;
    else if(s=='C')
        cout<<'G'<<endl;


    return 0;
}
