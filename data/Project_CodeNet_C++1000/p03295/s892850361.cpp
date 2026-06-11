#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){return a.second < b.second;}

int main(void){
    
    int N,M;
    
    cin >> N >> M;
    
    vector<pair<int,int>> v;
    v.resize(M);
    for(int i = 0; i < M;i++)cin >> v[i].first >> v[i].second;
    
    sort(v.begin(),v.end(),comp);
    int mx = 0;
    int cont = 0;

    for(auto u:v){
        
        if(mx <= u.first){
            cont++;
            mx = u.second;
        }
    }
    
    cout << cont << endl;
    return 0;
    
}
