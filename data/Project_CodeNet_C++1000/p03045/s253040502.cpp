#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
#include <set>
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
    init(n);
    LL x;
    LL y;
    LL z;
    for(LL i=0; i<m; i++){
        cin >> x >> y >>z;
        x--;
        y--;
        unite(x,y);
    }

    set<LL> s;
    for(LL i=0; i<n; i++){
        LL tmp=find(i);
        s.insert(tmp);
    }

    cout << s.size() << endl;

    return 0;
}
