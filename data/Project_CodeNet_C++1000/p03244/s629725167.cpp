#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    set<int> st1;
    map<int,int> mp1;
    set<int> st2;
    map<int,int> mp2;
    int v;
    for(int i = 0; i < N;i++){
        cin >> v;
        if(i%2==0){
            st1.insert(v);
            mp1[v]++;
        }else{
            st2.insert(v);
            mp2[v]++;
        }
    }
    
    vector<tuple<int,int,int>> vec1;
    vector<tuple<int,int,int>> vec2;
    for(auto itr = st1.begin(); itr != st1.end(); ++itr) {
        vec1.push_back(make_tuple(mp1[*itr],*itr,1)); 
    }
    
    for(auto itr = st2.begin(); itr != st2.end(); ++itr) {
        vec2.push_back(make_tuple(mp2[*itr],*itr,2)); 
    }
    
    sort(vec1.begin(),vec1.end(),greater<tuple<int,int,int>>());
    sort(vec2.begin(),vec2.end(),greater<tuple<int,int,int>>());
    //for(auto u:vec)cout <<get<0>(u)<<" "<<get<1>(u)<<" "<<get<2>(u)<<endl;
    
    // if(vec.size()==2){
    //     if(get<1>(vec[0])==get<1>(vec[1])){cout << N/2 << endl;return 0;}
    // }
    
    int cont = 0;
    if(get<1>(vec1[0])!=get<1>(vec2[0])){
        cont += get<0>(vec1[0])+get<0>(vec2[0]);
    }else if(get<0>(vec1[0]) < get<0>(vec2[0])){
        cont += get<0>(vec1[1])+get<0>(vec2[0]);
    }else if(get<0>(vec1[0]) > get<0>(vec2[0])){
        cont += get<0>(vec1[0])+get<0>(vec2[1]);
    }else if(get<0>(vec1[1]) > get<0>(vec2[1])){
        cont += get<0>(vec1[1])+get<0>(vec2[0]);
    }else if(get<0>(vec1[1]) <= get<0>(vec2[1])){
        cont += get<0>(vec1[0])+get<0>(vec2[1]);
    }
 
    cout << N - cont << endl;
    
}

