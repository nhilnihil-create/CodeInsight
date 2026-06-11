#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll h,w,n,X,Y;cin>>h>>w>>n>>X>>Y;
    string s,t;cin>>s>>t;

    for(int j=0;j<4;j++){
        ll x=X,y=Y;
        if(j==0){
            rep(i,0,n){if(s[i]=='U')x--;
            else if(s[i]=='L')y--;
            if(x<1||y<1){
                cout<<"NO"<<endl;
                return 0;
            }
            
            if(x+1<=h&&t[i]=='D')x++;
            if(y+1<=w&&t[i]=='R')y++;}
        }
        else if(j==1){
            rep(i,0,n){if(s[i]=='U')x--;
            else if(s[i]=='R')y++;
            if(x<1||y>w){
                cout<<"NO"<<endl;
                return 0;
            }
            
            if(x+1<=h&&t[i]=='D')x++;
            if(y-1>=1&&t[i]=='L')y--;}
        }
        else if(j==2){
            rep(i,0,n){if(s[i]=='D')x++;
            else if(s[i]=='L')y--;
            if(x>h||y<1){
                cout<<"NO"<<endl;
                return 0;
            }
            
            if(x-1>=1&&t[i]=='U')x--;
            if(y+1<=w&&t[i]=='R')y++;}
        }
        else if(j==3){
            rep(i,0,n){if(s[i]=='D')x++;
            else if(s[i]=='R')y++;
            if(x>h||y>w){
                cout<<"NO"<<endl;
                return 0;
            }
            
            if(x-1>=1&&t[i]=='U')x--;
            if(y-1>=1&&t[i]=='L')y--;}
        }
    }
    cout<<"YES"<<endl;
}

    







