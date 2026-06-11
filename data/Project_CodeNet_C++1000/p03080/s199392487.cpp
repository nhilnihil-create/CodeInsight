#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    int r=0,b=0,n;
    cin>>n>>s;
    rep(i,n){
        if(s[i]=='R')r++;
        else b++;
    }
    cout<<(r>b?"Yes":"No")<<endl;
}