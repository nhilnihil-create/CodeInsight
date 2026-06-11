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

    cin>>h>>w;
    char l1[h+1][w+1];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>l1[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(l1[i][j]=='#'){
                ll x=0;
                for(int k=0;k<4;k++){
                    ll a=i+direction2[k][0];
                    ll b=j+direction2[k][1];
                    //cout<<a<<" "<<b<<endl;
                    if(valid(a,b)&&l1[a][b]=='#')x++;
                }
                //cout<<"<"<<x<<">"<<endl;
                if(x==0){
                    cout<<"No";return 0;
                }
            }
        }
    }
    cout<<"Yes";
}
