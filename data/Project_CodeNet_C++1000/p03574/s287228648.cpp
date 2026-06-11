#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[51][51];
ll dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};

int main()
{
    ll n,k,m;
    cin>>n>>m;ll x,s=0,a,b;
    string s1[51];
    for(int i=0;i<n;i++){
        cin>>s1[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s1[i][j]=='#'){
                for(int k=0;k<8;k++){
                    //for(int l=0;l<2;l++){
                        ll c=i+dir[k][0];
                        ll d=j+dir[k][1];
                        if(c>=0&&c<n&&d>=0&&d<m&&s1[c][d]=='.')l1[c][d]++;
                    //}
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s1[i][j]!='#')cout<<l1[i][j];
            else cout<<s1[i][j];
        }cout<<endl;
    }
}
