#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    string S,T="",mir="",L="",R="";
    ll a=0,ans=0,l=0,r=0;
    cin>>S;
    for(ll i=0;i<S.size();i++){
        if(S[i]!='x') T+=S[i];
    }
    
    for(ll i=0;i<T.size()/2;i++){
        if(T[i]!=T[T.size()-i-1]){
            cout<<"-1"<<endl;
            return 0;
        }
        mir+=T[i];
    }
    if(T.size()%2==1) mir+=T[T.size()/2]; 
    
    for(ll i=0;i<S.size();i++){
        L+=S[i];
        if(S[i]==mir[a]) a++;
        if(a==mir.size()) break;
    }
    a=0;
     for(ll i=S.size()-1;i>=0;i--){
        R+=S[i];
        if(S[i]==mir[a]) a++;
        if(a==mir.size()) break;
    }
    
    while(1){
        if(L[l]==R[r]){
            l++;
            r++;
        }else if(L[l]=='x'){
            l++;
            ans++;
        }else if(R[r]=='x'){
            r++;
            ans++;
        }
        if(l==L.size()&&r==R.size()) break;
    }
    cout<<ans<<endl;
}