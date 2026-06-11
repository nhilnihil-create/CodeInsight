#include<bits/stdc++.h>
using namespace std;

string ans;vector<int> abcd;bool check=false;

string solve(int count,int sum)
{
if(check)return ans;
if(count==3&&sum==7){check=true;return ans;}
if(count<3&&!check){ans.replace(count*2+1,1,"+");ans=solve(count+1,sum+abcd[count+1]);}
if(count<3&&!check){ans.replace(count*2+1,1,"-");ans=solve(count+1,sum-abcd[count+1]);}
return ans;
}

int main()
{
string S;cin>>S;abcd.resize(4);
for(int i=0;i<4;i++)abcd[i]=S[i]-'0';
ans=to_string(abcd[0])+"+"+to_string(abcd[1])+"+"+to_string(abcd[2])+"+"+to_string(abcd[3])+"=7";
cout<<solve(0,abcd[0]);
}
