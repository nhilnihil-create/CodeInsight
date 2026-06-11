#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll>mp;

int main ()
{
    map<char,char>mp;
    mp['A']='T';
    mp['T']='A';
    mp['C']='G';
    mp['G']='C';
    char b;
    cin>>b;
    cout<<mp[b]<<endl;
    return 0;

}
