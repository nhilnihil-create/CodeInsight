#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end() 

int const N = 200001;
int n, m; 
vector<pair<int,int>> g[N];
string id[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i<m; ++i){
         int x, y; 
         scanf("%d%d", &x, &y);
         g[x].push_back({y, i+1});
    }
    for(int i = 1; i<=n; ++i){
        sort(all(g[i]));
        int c = 1; 
        string x = "";
        stringstream ss; 
        ss << i; 
        ss >> x;
        while(x.size() < 6)x = '0'+x;
        for(auto j: g[i]){
            id[j.second] = x;
            string y = "";
            ss.clear();
            ss << c; 
            ss >> y; 
            while(y.size() < 6)y = '0'+y;
            id[j.second] += y;
            ++c;  
        }
    }
    for(int i = 1; i<=m; ++i)printf("%s\n", id[i].c_str());
}