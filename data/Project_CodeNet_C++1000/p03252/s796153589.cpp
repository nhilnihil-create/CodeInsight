#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using graph=vector<vector<int>>;
using field=vector<string>;
using p =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    string s,t;
    cin>>s>>t;
    int len=s.size();
    vector<int> a(26,-1);
    vector<int> b(26,-1);
    rep(i,len){
        int p=s[i]-'a';
        int q=t[i]-'a';

        if(a[p]!=-1||b[q]!=-1){
            if(a[p]!=q||b[q]!=p){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            a[p]=q;
            b[q]=p;
        }
    }
    cout<<"Yes"<<endl;
}

