#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
vector<int> g[200020];
int d[200020];
bool used[200020];
void dfs(int x){
    used[x]=1;
    for(auto y:g[x]){
        if(!used[y]){
            d[y]=d[x]+1;
             dfs(y);
        }
    }
}
int main()
{
	cin>>n;
    for(int i=0; i<n-1; i++){
        int x, y; cin>>x>>y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    int r=0;
    for(int i=1; i<n; i++){
        if(d[r]<d[i]) r=i;
    }
    fill(used, used+n, 0);
    d[r]=0;
    dfs(r);
    if(*max_element(d, d+n)%3==1) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
	return 0;
}