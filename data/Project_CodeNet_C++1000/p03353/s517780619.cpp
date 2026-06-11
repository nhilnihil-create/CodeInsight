#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    int k;cin>>k;
    priority_queue<string, vector<string>, greater<string> > que;
    vector<vector<int>> v(26);
    rep(i,s.size()){
        v[s[i]-'a'].push_back(i);
    }
    int dk=k;
    map<string,int> mp;
    rep(i,26){
        priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>> > que2;
        rep(j,v[i].size()){
            int l=v[i][j];
            string now="";
            now+=s[l];
            que2.push({now,l});
        }
        while(que2.size()){
            string now=que2.top().first;int id=que2.top().second;
            que2.pop();
            if(mp[now]==0)dk--;
            if(dk==0){
                cout<<now<<endl;
                return 0;
            }
            if(id==s.size()-1)continue;
            mp[now]++;
            id++;
            now+=s[id];
            que2.push({now,id});
        }
    }
}
