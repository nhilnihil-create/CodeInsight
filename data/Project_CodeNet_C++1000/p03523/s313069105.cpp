#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define ll int64_t
using namespace std;

bool compare_by_b(pair<string,int> a,pair<string,int> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

int main(){
    int c=0;
    string s,w;
    cin>>s;
    rep(i,s.size()) if(s.at(i)!='A') w.push_back(s.at(i));
    rep(i,s.size()-1) if(s.at(i)==s.at(i+1)){
        cout<<"NO"<<endl;
        return 0;
    }
    if(w=="KIHBR" && c<=4) {
        rep(i,s.size()-4) if(s.at(i)=='K' && s.at(i+1)=='I' && s.at(i+2)=='H'){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
