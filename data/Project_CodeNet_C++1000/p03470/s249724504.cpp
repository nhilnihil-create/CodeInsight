#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
map<int,int>mp;
vector<int>v;
int n;
cin >> n;
for(int i=0; i<n; i++)
{
    int x ;
    cin >> x;
    if(!mp[x])
        v.push_back(x);
    mp[x]++;
}
cout << v.size() << endl;

}
