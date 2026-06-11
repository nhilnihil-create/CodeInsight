#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;

    int r=0,b=0;
    rep(i,n){
        if(s[i] == 'R')++r;
        else ++b;
    }
    if(r > b)cout<<"Yes";
    else cout<<"No";
}