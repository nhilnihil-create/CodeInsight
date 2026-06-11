#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){

int n;
string s;
cin >> s;
cin >> n;
map<string,int>mp;
int ln = s.size();vector<string>v;
for(int i=0; i<s.size(); i++)
{
    string blnk = "" ;
    for(int j=i; j<min(i+5,ln); j++)
    {
        blnk += s[j];
        if(!mp[blnk])
        {v.push_back(blnk);
        mp[blnk]++;
        }
    }
}
sort(v.begin(),v.end());

cout << v[n-1] << endl;

}
