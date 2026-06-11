# include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
string s,cal,kcal;
char j,k,l;
int main(){ 
    cin>>a>>b;
    if(a%2==0 && a/2>=b) cout<<"YES\n";
    else if(a%2==0) cout<<"NO\n";
    if(a%2!=0 && (a/2)+1>=b) cout<<"YES\n";
    else if(a%2!=0) cout<<"NO\n";
}