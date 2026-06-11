#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define rforn(a, n) for(int a = (n)-1; a>=0; --a)
using namespace std;
const int N = 6e5+20;

int main()
{
    int n;
    cin>>n;
    int par = n/2;
    int im = n - par;
    cout<<par*im<<endl;

}