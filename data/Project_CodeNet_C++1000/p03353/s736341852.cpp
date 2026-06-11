#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod = 1e9+7;
const int maxn=2e5+7;
typedef vector<map<char,int>> vmap;

void insertstring(string s,vmap &trie){
    int cc,cn=0;

    for(int i=0;i<s.length();i++){
        char cc = s[i];
        if(trie[cn].count(cc)){
            cn = trie[cn][cc];
        }
        else{
            trie.resize(trie.size()+1);
            trie[cn][cc] = trie.size()-1;
            cn = trie.size()-1;
        }
    }
}

string dfs(vmap trie,int &k,int x){
    if(k==0) return "";
    map<char,int> br = trie[x];
    string tmp="";
    for(auto i:br){
        tmp = i.first + dfs(trie,--k,i.second);
        if(k==0){
            return tmp;
        }
    }
    return tmp;
}

int main(){
    int k,k1;
    string s;
    cin>>s>>k;
    k1=k;
    vmap trie(1);
    
    for(int i=0;i<26;i++){
        for(int j=0;j<s.length();j++){
            if(s[j]-'a' == i){
                insertstring(s.substr(j),trie);                
            }            
        }
        string ans = dfs(trie,k,0);
        if(k==0){
            cout<<ans;
            break;
        }
        else k=k1;
    }

    

}