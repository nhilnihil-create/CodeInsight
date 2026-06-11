#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

vector<LL> parent(MAX);
vector<LL> length(MAX);

void init(LL n){
    for(LL i=0; i<n; i++){
        parent[i]=i;
        length[i]=1;
    }
}

int find(LL x){
    while(parent[x]!=x){
        x=parent[x];
    }
    return x;
}

bool same(LL x, LL y){
    return find(x)==find(y);
}

bool unite(LL x, LL y){
    x=find(x);
    y=find(y);
    if(x==y){
        return false;
    }
    if(length[x]<length[y]){
        swap(x,y);
    }
    parent[y]=x;
    length[x]+=length[y];
    return true;
}

int main(){
    LL n;
    LL m;
    cin >> n >> m;
    vector<LL> p(n);
    vector<vector<LL>> pg(n);
    LL x;
    LL y;
    for(LL i=0; i<n; i++){
        cin >> p[i];
        p[i]--;
    }
    init(n);
    for(LL i=0; i<m; i++){
        cin >> x >> y;
        x--;
        y--;
        unite(x,y);
    }

    for(LL i=0; i<n; i++){
        LL tmp=find(i);
        pg[tmp].push_back(i);
    }

    LL ans=0;
    for(LL i=0; i<n; i++){
        vector<LL> num;
        vector<LL> val; 
        if(pg[i].size()!=0){
            for(LL j=0; j<pg[i].size(); j++){
                num.push_back(pg[i][j]);
                val.push_back(p[pg[i][j]]);
            }
            sort(num.begin(), num.end());
            sort(val.begin(), val.end());
            LL idx_n=0;
            LL idx_v=0;
            while(idx_n<num.size() && idx_v<val.size()){
                if(num[idx_n]<val[idx_v]){
                    idx_n++;
                }else if(num[idx_n]>val[idx_v]){
                    idx_v++;
                }else{
                    ans++;
                    idx_n++;
                    idx_v++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
