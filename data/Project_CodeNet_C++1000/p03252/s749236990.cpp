#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define nl cout<<"\n"
#define dbg(x) cout<<x<<" ";
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define UM unordered_map<char,int>
#define ULL unordered_map<ll,int>
void fun(){
    string s,t; cin>>s>>t;
    UM ms,mt;
    int S=1,T=1;
    fi(0,s.size()){
        if(ms[s[i]]!=mt[t[i]]){
            cout<<"No\n";
            return ;
        }
        if(ms[s[i]]==0){
            ms[s[i]]=S;
            S++;
        }
        if(mt[t[i]]==0){
            mt[t[i]]=T;
            T++;
        }
    }
    cout<<"Yes\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   fun();
}