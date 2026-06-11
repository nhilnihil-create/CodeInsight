#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
using namespace std;
int main(void){
    int ans=1;
    string s;
    cin>>s;
    string t="AKIHABARA";
    for(int i=0;i<t.length();i++){
        if(s[i]!=t[i]){
            s.insert(s.begin()+i,'A');
        }
    }
    if(s.length()!=t.length())ans=0;
    for(int i=0;i<t.length();i++){
        if(s[i]!=t[i])ans=0;
    }
    cout<<(ans?"YES":"NO")<<endl;
}
    
  