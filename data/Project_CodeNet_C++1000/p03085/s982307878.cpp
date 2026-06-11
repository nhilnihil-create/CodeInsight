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
    char b;
    cin>>b;
    map<char,char> ans;
    ans['A']='T';
    ans['T']='A';
    ans['C']='G';
    ans['G']='C';
    cout<<ans[b]<<endl;
}