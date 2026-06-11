#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> P;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
#define MAX 100000


int main(){
    string s,t;
    cin>>s>>t;
    if(s.size()<t.size())cout<<"UNRESTORABLE";
    else{ 
        int size=s.size()-t.size();
        int index;
        for(int i=size;i>=0;i--){
            bool flag=false;
            rep(j,t.size()){
                if(s[j+i]!=t[j]&&s[i+j]!='?'){
                    flag=true;
                  	index=-1;
                    break;
                }
            }
            if(!flag){
                index=i;
                break;
            }
        }
        if(index==-1)cout<<"UNRESTORABLE";
        else{
            rep(i,s.size()){
                if(index<=i&&i<index+t.size()){
                    cout<<t[i-index];
                }
                else {
                    if(s[i]=='?')cout<<'a';
                    else cout<<s[i];
                } 
            }
        }
    }
    return 0;
}
    

