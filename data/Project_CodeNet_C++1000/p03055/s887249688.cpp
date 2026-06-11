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

using namespace std;

vector<vector<int> > g;

void dfs( int curr, int currd, vector<int>& depth )
{
    depth[curr]=currd;

    int i;
    for(i=0; i<(int)g[curr].size(); i++) {
        int next = g[curr][i];
        if(depth[next]<0) {
            dfs(next, currd+1, depth);
        }
    }

    return;
}

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    g.resize(n);
    int i;
    for(i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    vector<int> depth(n,-1);
    dfs(0, 0, depth);

    int maxid=-1;
    int max=-1;
    for(i=0; i<n; i++) {
        if(depth[i]>max) {
            max=depth[i];
            maxid=i;
        }
    }

    vector<int> depth2(n,-1);
    dfs(maxid, 0, depth2);
    int maxid2=-1;
    int max2=-1;
    for(i=0; i<n; i++) {
        if(depth2[i]>max2) {
            max2=depth2[i];
            maxid2=i;
        }
    }
    if(max2%3==1) {
        printf("Second\n");
    }
    else {
        printf("First\n");
    }

    return 0;
}
