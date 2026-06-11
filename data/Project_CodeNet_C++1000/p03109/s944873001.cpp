#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    string s;
    cin>>s;
    int m=stoi(s.substr(5,2)),d=stoi(s.substr(8,2));
    if (m<4)
        cout<<"Heisei\n";
    else if (m==4 && d<=30)
        cout<<"Heisei\n";
    else
        cout<<"TBD\n";
}