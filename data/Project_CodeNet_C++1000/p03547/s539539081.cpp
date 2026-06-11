#include <bits/stdc++.h>
using namespace std;
char a,b;
int x,y;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>a>>b;

if(a=='A')x=10;
else if(a=='B')x=11;
else if(a=='C')x=12;
else if(a=='D')x=13;
else if(a=='E')x=14;
else x=15;
if(b=='A')y=10;
else if(b=='B')y=11;
else if(b=='C')y=12;
else if(b=='D')y=13;
else if(b=='E')y=14;
else y=15;
if(x>y)cout<<'>';
else if(x<y) cout<<'<';
else cout<<'=';



return 0;}

