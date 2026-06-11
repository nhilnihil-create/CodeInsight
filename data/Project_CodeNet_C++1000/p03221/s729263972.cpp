#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

string padit(int index){
    int digits=0;
    stack<int>st;
    while(index!=0){
        st.push(index%10);
        index/=10;
        digits++;
    }
    digits=6-digits;
    string result="";
    while(digits){
        result+='0';
        digits--;
    }
    while(!st.empty()){
        result+=st.top()+'0';
        st.pop();
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>v;
    unordered_map<int,vector<int>>ump;
    for(int i=0;i<m;i++)
    {
        int p,y;
        cin>>p>>y;
        v.push_back({p,y});
        ump[p].push_back(y);
    }
    for(auto it=ump.begin();it!=ump.end();it++)
    {
        sort(ump[it->first].begin(),ump[it->first].end());
    }
    for(int i=0;i<v.size();i++)
    {
        int f=v[i].first;
        int s=v[i].second;
        auto it=lower_bound(ump[f].begin(),ump[f].end(),s);
        int index=it-ump[f].begin();
        string result="";
        result+=padit(f);
        result+=padit(index+1);
        cout<<result<<endl;
    }
}