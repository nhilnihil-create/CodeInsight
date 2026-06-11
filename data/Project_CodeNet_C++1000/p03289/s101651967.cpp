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
    string s;
    cin>>s;
    if(s[0]!='A'){
        cout<<"WA";return 0;
    }
    ll x=0;
    for(int i=2;i<s.size()-1;i++){
        if(s[i]=='C')x++;
        if(x>1){
            cout<<"WA";return 0;
        }
    }
    if(x==0){cout<<"WA";return 0;}
    for(int i=1;i<s.size();i++){
        if(s[i]!='C'&&s[i]>='A'&&s[i]<='Z'){
            cout<<"WA";return 0;
        }
    }
    cout<<"AC";
}
