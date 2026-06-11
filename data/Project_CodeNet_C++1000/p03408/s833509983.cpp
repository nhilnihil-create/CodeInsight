#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    map<string,int>red;
    map<string,int>blue;
    queue<string>str;
    int max=0;
    int n,m;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        str.push(s);
        if(blue.count(s)){
            blue[s]++;
        }else{
            blue[s]=1;
        }
    }
    cin>>m;
    rep(i,m){
        string s;
        cin>>s;
        str.push(s);
        if(red.count(s)){
            red[s]++;
        }else{
            red[s]=1;
        }
    }
    int l;
    int d=str.size();
    rep(i,d){
        string s=str.front();
        if(!blue.count(s))continue;
        if(!red.count(s)){
            l=blue[s];
        }else{
            l=blue[s]-red[s];
        }
        if(l>max){
            max=l;
        }
        str.pop();
    }
    cout<<max<<endl;
}
