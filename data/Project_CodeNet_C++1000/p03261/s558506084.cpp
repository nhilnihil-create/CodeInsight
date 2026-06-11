#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    set<string> list;
    cin>>n;
    string w;
    char s;
    int size=list.size();
    bool flg=true;
    rep(i,n){
        cin>>w;
        list.insert(w);
        if(size==list.size()){
            flg=false;
            // cout<<"double:"<<w<<endl;
        }
        size=list.size();

        if(i==0){
            s = w[w.size()-1];
        }else{
            if(s!=w[0]){
                flg=false;
                // cout<<"no siritori:"<<s<<","<<w<<endl;
            }
            s = w[w.size()-1];
        }
    }

    if(flg==false) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

}

