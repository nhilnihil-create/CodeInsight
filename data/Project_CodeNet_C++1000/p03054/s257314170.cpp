#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
int dir[4];
int dit[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int x,y;
    cin>>x>>y;
    cin>>s>>t;
    int f=0;
    int pos=x;
    for(int i=0;s[i];++i){
        if(s[i]=='U')
            pos--;
        if(pos<=0){
            f=1;
            break;
        }
        if(t[i]=='D'&&pos<n)
            pos++;
    }
    if(f){puts("NO");return 0;}
    pos=x;
    for(int i=0;s[i];++i){
        if(s[i]=='D')
            pos++;
        if(pos>n){
            f=1;
            break;
        }
        if(t[i]=='U'&&pos>1)
            pos--;
    }
    if(f){puts("NO");return 0;}
    pos=y;
    for(int i=0;s[i];++i){
        if(s[i]=='L')
            pos--;
        if(pos<=0){
            f=1;
            break;
        }
        if(t[i]=='R'&&pos<m)
            pos++;
    }
    if(f){puts("NO");return 0;}
    pos=y;
    for(int i=0;s[i];++i){
        if(s[i]=='R')
            pos++;
        if(pos>m){
            f=1;
            break;
        }
        if(t[i]=='L'&&pos>1)
            pos--;
    }
    if(f){puts("NO");return 0;}
    else puts("YES");
}
