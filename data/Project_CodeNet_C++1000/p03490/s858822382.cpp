#include <bits/stdc++.h>
using namespace std;
vector<int>vec[2];
int x, y;

int wid(){
    set<int>st[2];
    st[0].insert(0);
    for(int i=0;i<vec[0].size();i++){
        for(auto it = st[i%2].begin();it!=st[i%2].end();it++){
            st[(i+1)%2].insert((*it)+vec[0][i]);
            st[(i+1)%2].insert((*it)-vec[0][i]);
        }
        st[i%2].clear();
    }
    for(auto it = st[vec[0].size()%2].begin(); it!=st[vec[0].size()%2].end();it++){
        if((*it)==x)return 1;
    }
    return 0;
}
int hei(){
    set<int>st[2];
    st[0].insert(0);
    for(int i=0;i<vec[1].size();i++){
        for(auto it = st[i%2].begin();it!=st[i%2].end();it++){
            st[(i+1)%2].insert((*it)+vec[1][i]);
            st[(i+1)%2].insert((*it)-vec[1][i]);
        }
        st[i%2].clear();
    }
    for(auto it = st[vec[1].size()%2].begin(); it!=st[vec[1].size()%2].end();it++){
        if((*it)==y)return 1;
    }
    return 0;
}

int main(){
    string s;
    cin>>s;    
    cin>>x>>y;
    for(int i=0, flg = 1, p = 0;i<s.size();i++){
        if(flg && s[i]=='F'){
            x--;
            continue;
        }
        else flg = 0;
        if(s[i]=='T'){
            p = (p+1)%2;
            vec[p].push_back(0);
        }
        else{
            vec[p][vec[p].size()-1]++;
        }
    }
    if(wid()&&hei()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}