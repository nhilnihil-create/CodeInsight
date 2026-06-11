#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

int main() {
    int a,b;
    cin>>a>>b;
    if(a+b==15)
        cout<<"+"<<"\n";
    else if(a*b==15)
        cout<<"*"<<"\n";
    else
        cout<<"x"<<"\n";
    
}