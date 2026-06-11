#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){

int h,w,N;
cin>>h>>w>>N;
int sr,sc;
cin>>sr>>sc;
string s;
string t;
cin>>s;
cin>>t;
bool yes=true;
{
    int l=1,r=w;

    for(int i=N-1;i>-1;i--){
        if(t[i]=='L')r=min(w,r+1);
        if(t[i]=='R')l=max(1,l-1);
        if(s[i]=='L')l++;
        if(s[i]=='R')r--;
    if(l>r)yes=false;
    }
    yes&=(l<=sc && sc<=r);

}

{
    int l=1,r=h;

    for(int i=N-1;i>-1;i--){
        if(t[i]=='U')r=min(h,r+1);
        if(t[i]=='D')l=max(1,l-1);
        if(s[i]=='U')l++;
        if(s[i]=='D')r--;
    if(l>r)yes=false;
    }
    yes&=(l<=sr && sr<=r);
    
}
cout<<(yes ? "YES":"NO")<<endl;


 return 0;
}
/*
firsr 解説AC 2h 07m 20s

2 3 3
2 2
RRL
LUD

YES


4 3 5
2 2
UDRRR
LLDUD

NO

5 6 11
2 1
RLDRRUDDLRL
URRDRLLDLRD

NO
*/
