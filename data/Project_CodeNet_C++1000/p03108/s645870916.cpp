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

int main() {
    LL n;
    LL m;
    cin >> n >> m;
    LL tmp_a;
    LL tmp_b;
    vector<pair<LL, LL>> ab;
    for(LL i=0; i<m; i++){
        cin >> tmp_a >> tmp_b;
        tmp_a--;
        tmp_b--;
        ab.push_back(make_pair(tmp_a, tmp_b));
    }
    reverse(ab.begin(), ab.end());
    init(n);
    vector<LL> color_num(n, 1);
    vector<LL> ans(m);
    ans[0]=(n*(n-1))/2;
    for(LL i=1; i<m; i++){
        LL p0=find(ab[i-1].first);
        LL p1=find(ab[i-1].second);
        //cout << i << " " << p0 << " " << p1 << endl;
        if(p0!=p1){
            LL tmp0=color_num[p0];
            LL tmp1=color_num[p1];
            LL tmp2=tmp0+tmp1;
            ans[i]=ans[i-1]-(tmp2*(tmp2-1))/2+(tmp0*(tmp0-1))/2+(tmp1*(tmp1-1))/2;
            unite(p0, p1);
            LL p2=find(p0);
            //cout << i << " " << p0+1 << " " << p1+1 << " " << p2+1 << endl;
            if(p2!=p0){
                color_num[p1]=color_num[p0]+color_num[p1];
                color_num[p0]=0;
            }else{
                color_num[p0]=color_num[p0]+color_num[p1];
                color_num[p1]=0;
            }
        }else{
            ans[i]=ans[i-1];
        }
    }

    //for(int i=0; i<n; i++){
    //    cout << i+1 << " " << color_num[i] << endl;
    //}

    //LL p0 = find(ab[m-1].first);
    //LL p1 = find(ab[m-1].second);

    //cout << p0+1 << " " << p1+1 << endl;

    reverse(ans.begin(), ans.end());
    for(LL i=0; i<m; i++){
        cout << ans[i] << endl;
    }

    return 0;
}