#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int ans=1;
    string s;
    cin>>s;
    string t="AKIHABARA";
    for(i=0;i<t.length();i++){
        if(s[i]!=t[i]){
            s.insert(s.begin()+i,'A');
        }
    }
    if(s.length()!=t.length())ans=0;
    for(i=0;i<t.length();i++){
        if(s[i]!=t[i])ans=0;
    }
    cout<<(ans?"YES":"NO")<<endl;
}