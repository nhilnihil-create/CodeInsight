#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;
 

int main(int argc, char* argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<long> > z(n), w(n);
    vector<int> cnt(n);
    long i;
    for(i=0; i<n+m-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        z[a-1].push_back(b-1);    // par->child
        w[b-1].push_back(a-1);    // child->par
        cnt[b-1]++;
    }

    vector<int> topo(n);
    set<int> ss;
    for(i=0; i<n; i++) {
        if(cnt[i]==0) ss.insert(i);
    }
    int count=0;
    while(!ss.empty()) {
        auto it=ss.begin();
        topo[*it]=count;
        count++;

        long m;
        for(m=0; m<(long)z[*it].size(); m++) {
            cnt[z[*it][m]]--;
            if(cnt[z[*it][m]]==0) ss.insert(z[*it][m]);
        }
        ss.erase(it);
    }
    if(count!=n) return 12;

    for(i=0; i<n; i++) {
        int max=-1;
        int maxk=-1;
        int k;
        for(k=0; k<w[i].size(); k++) {
            if(max<topo[w[i][k]]) {
                max=topo[w[i][k]];
                maxk=w[i][k];
            }
        }
        printf("%d\n", maxk+1);
    }

    return 0;
}
