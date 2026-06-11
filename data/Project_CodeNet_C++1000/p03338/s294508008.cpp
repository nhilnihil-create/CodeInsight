#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    for(int i=1;i<n;i++){
        string x=s.substr(0,i);
        string y=s.substr(i);
        int tmp=0;
        for(char c='a';c<='z';c++){
            bool left=false,right=false;
            for(int j=0;j<x.size();j++){
                if(c==x[j]) left=true;
            }
            for(int j=0;j<y.size();j++){
                if(c==y[j]) right=true;
            }
            if(left&&right) tmp++;
        }
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}