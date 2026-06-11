#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <ios>
#include <iomanip>
#define ll long long
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> P(m),Y(m);
    for(int i=0;i<m;i++){
        cin>>P[i]>>Y[i];
        P[i]--;
    }
    vector<vector<int>>vals(n);
    for(int i=0;i<m;i++){
        vals[P[i]].push_back(Y[i]);
    }
    for(int i=0;i<n;i++){
        sort(vals[i].begin(),vals[i].end());
        vals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());
    }
    for(int i=0;i<m;i++){
        int v=P[i];
        cout<<setfill('0')<<right<<setw(6)<<v+1;

        int id=lower_bound(vals[v].begin(),vals[v].end(),Y[i])-vals[v].begin();
        cout<<setfill('0')<<right<<setw(6)<<id+1;
        cout<<endl;
    }

    return 0;
}