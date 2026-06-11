#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> V(N);
    for(int i = 0; i < N; i++) cin >>V[i];
    map<int,int> mp1,mp2;
    set<int> st1,st2;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){mp1[V[i]]++; st1.insert(V[i]);}
        else {mp2[V[i]]++; st2.insert(V[i]);}
    }
    vector<pair<int,int>> vec1,vec2;
    
    for(auto s:st1)vec1.push_back(make_pair(mp1[s],s));
    for(auto s:st2)vec2.push_back(make_pair(mp2[s],s));
    sort(vec1.begin(),vec1.end(),greater<pair<int,int>>());
    sort(vec2.begin(),vec2.end(),greater<pair<int,int>>());
    
    if(vec1[0].second != vec2[0].second)cout << N - vec1[0].first - vec2[0].first << endl;
    else if( vec1[0].first + vec2[1].first >  vec1[1].first + vec2[0].first ){
        cout << N - vec1[0].first - vec2[1].first << endl;
    }else{
        cout << N - vec1[1].first - vec2[0].first << endl;
    }
    
    
}