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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;char s2;
    cin>>s;
    cin>>t;ll x=s.size();
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i=1;i<=x;i++){
        s2=s[0];
        s.erase(0,1);
        s+=s2;
//        cout<<s<<endl;
//        cout<<t<<endl;
        if(s==t){
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";
}
