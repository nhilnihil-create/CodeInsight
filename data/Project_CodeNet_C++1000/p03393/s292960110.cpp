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
    string S;
    cin>>S;
    set<char> s;
    for(int i=0;i<S.size();i++) s.insert(S[i]);
    
    if(S.size()!=26){
        char cha;
        for(cha='a';cha<='z';cha++) if(!s.count(cha)) break;
        cout<<S<<cha<<endl;
        return 0; 
    }else{
        vector<char> v;
        for(int i=0;i<26;i++) v.push_back(S[i]);
        if(next_permutation(v.begin(),v.end())){
            string t="";
            for(int j=0;j<v.size();j++){
                t+=v[j];
                if(v[j]!=S[j]) break;
            }
            cout<<t<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
}