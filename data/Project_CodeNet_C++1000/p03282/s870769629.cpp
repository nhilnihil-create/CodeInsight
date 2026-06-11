#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    long long int k;
    cin>>s>>k;
    int one=0;
    for(i=0;s[i]=='1';i++){one++;}
    if(k==1)cout<<s[0]<<endl;
    else if(k<=one)cout<<1<<endl;
    else cout<<s[one]<<endl;
}