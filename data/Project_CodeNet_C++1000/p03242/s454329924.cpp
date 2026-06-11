#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;

const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    string s;
    cin>>s;
    rep(i,3){
        if(s[i]=='1')s[i]='9';
        else if(s[i]=='9')s[i]='1';
    }
    cout<<s<<endl;
}