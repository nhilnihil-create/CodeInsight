#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define GI(i) (scanf("%d",&i))
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
typedef long long LL;
using namespace std;

LL N,L[100000],R[100000];

int main(void){
    GLL(N);
    REP(i,N){
        GLL(L[i]);
        GLL(R[i]);
    }

    map<LL,set<LL> > left;
    map<LL,set<LL> > right;
    map<LL,pair<LL,LL> > id2lr;
    REP(i,N){
        if(left.find(-L[i])==left.end())
            left[-L[i]] = set<LL>({i});
        else
            left[-L[i]].insert(i);
        if(right.find(R[i])==right.end())
            right[R[i]] = set<LL>({i});
        else
            right[R[i]].insert(i);
        id2lr[i]=MP(L[i],R[i]);
        // printf("L[i] R[i] = %lld %lld\n",L[i],R[i]);
    }
    LL res = 0;
    LL ans = 0;
    LL pos = 0;
    LL NN = N;
    while(1){
        if(NN==0)
            break;
        NN--;
        LL l = -(*left.begin()).first;
        LL id = *(left[-l].begin());
        LL r = id2lr[id].second;
        // printf("l=%lld r=%lld id=%lld pos=%lld res=%lld __LINE__=%d\n",l,r,id,pos,res,__LINE__);
        left[-l].erase(id);
        if(left[-l].size()==0)
            left.erase(-l);
        right[r].erase(id);
        if(right[r].size()==0)
            right.erase(r);
        if(pos<l){
            res += l-pos;
            pos = l;
        }
        if(r<pos){
            res += pos-r;
            pos = r;
        }

        if(NN==0)
            break;
        NN--;
        r = (*right.begin()).first;
        id = *(right[r].begin());
        l = id2lr[id].first;
        // printf("l=%lld r=%lld id=%lld pos=%lld res=%lld\n",l,r,id,pos,res);
        right[r].erase(id);
        if(right[r].size()==0)
            right.erase(r);
        left[-l].erase(id);
        if(left[-l].size()==0)
            left.erase(-l);
        if(pos<l){
            res += l-pos;
            pos = l;
        }
        if(r<pos){
            res += pos-r;
            pos = r;
        }

    }
    res += (0<pos)?pos:-pos;
    ans = res;
    // printf("res = %lld pos=%lld\n",res,pos);

    left.clear();
    right.clear();
    id2lr.clear();
    REP(i,N){
        if(left.find(-L[i])==left.end())
            left[-L[i]] = set<LL>({i});
        else
            left[-L[i]].insert(i);
        if(right.find(R[i])==right.end())
            right[R[i]] = set<LL>({i});
        else
            right[R[i]].insert(i);
        id2lr[i]=MP(L[i],R[i]);
    }

    pos = 0;
    res = 0;
    NN = N;
    while(1){
        if(NN==0)
            break;
        NN--;
        LL r = (*right.begin()).first;
        LL id = *(right[r].begin());
        LL l = id2lr[id].first;
        right[r].erase(id);
        if(right[r].size()==0)
            right.erase(r);
        left[-l].erase(id);
        if(left[-l].size()==0)
            left.erase(-l);
        if(pos<l){
            res += l-pos;
            pos = l;
        }
        if(r<pos){
            res += pos-r;
            pos = r;
        }

        if(NN==0)
            break;
        NN--;
        l = -(*left.begin()).first;
        id = *(left[-l].begin());
        r = id2lr[id].second;
        // printf("l=%lld r=%lld id=%lld pos=%lld res=%lld\n",l,r,id,pos,res);
        left[-l].erase(id);
        if(left[-l].size()==0)
            left.erase(-l);
        right[r].erase(id);
        if(right[r].size()==0)
            right.erase(r);
        if(pos<l){
            res += l-pos;
            pos = l;
        }
        if(r<pos){
            res += pos-r;
            pos = r;
        }
        // printf("pos=%lld res=%lld\n",pos,res);
    }
    res += (0<pos)?pos:-pos;
    // printf("res = %lld\n",res);
    ans = max(res,ans);
    printf("%lld\n",ans);
    return 0;
}