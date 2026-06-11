#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main(){
    ios::sync_with_stdio(false); 
    string s1,s2;
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end()); 
    if(s1==s2) printf("YES\n");
    else printf("NO\n"); 
    return 0;
}