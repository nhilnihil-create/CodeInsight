#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h,w;
ll direction2[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
bool valid(int a,int b)
{
    if(a>=1&&a<=h&&b>=1&&b<=w)return true;
    else return false;
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    string s;
    cin>>s;
    ll k,y=0;
    cin>>k;vector<string>v,v2;

    ll x=0;map<string,ll>m;
    for(int i=min((ll)s.size(),5ll);i>=1;i--){
        for(int j=1;j<=s.size()-i+1;j++){
            if(m[s.substr(j-1,i)]!=1){x++;m[s.substr(j-1,i)]=1;v.push_back(s.substr(j-1,i));}
        }
    }
    sort(v.begin(),v.end());
    //for(auto i:v)cout<<i<<endl;
    cout<<v[k-1];return 0;
}
