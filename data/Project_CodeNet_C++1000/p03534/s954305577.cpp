#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string S;
    cin>>S;
    map<char,int> M;
    M['a']=0;
    M['b']=0;
    M['c']=0;
    int n=S.size();
    for(int i=0;i<n;i++) M[S[i]]++;
    if(M['a']==M['b'] && M['b']==M['c']) cout<<"YES"<<endl;
    else{
        int max_cnt=-1,min_cnt=INF;
        for(int i=0;i<3;i++){
            chmax(max_cnt,M['a'+i]);
            chmin(min_cnt,M['a'+i]);
        }
        if(max_cnt-min_cnt>=2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
