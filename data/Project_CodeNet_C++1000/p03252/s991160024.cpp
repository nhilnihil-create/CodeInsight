#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 1e9+10
using namespace std;
map <char,int>leta;
map <char,int>letb;
string s,t;
int num=1,sn[200005],tn[200005],yes=1;
int main(){
    cin>>s;
    cin>>t;
    for(int i=0;i<s.size();i++){
        if(!leta[s[i]])
            leta[s[i]]=num++;
        sn[i]=leta[s[i]];
    }
    num=1;
    for(int i=0;i<t.size();i++){
        if(!letb[t[i]])
            letb[t[i]]=num++;
        tn[i]=letb[t[i]];
    }
    for(int i=0;i<s.size();i++){
        if(sn[i]!=tn[i]||s.size()!=t.size()){
            yes=0;
            break;
        }
    }
    if(yes)
        printf("Yes");
    else
        printf("No");

}
