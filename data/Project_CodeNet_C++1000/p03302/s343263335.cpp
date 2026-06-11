#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<sstream>
#include<list>
#include<climits>

using namespace std;
#define rep(i,i0,n) for(int i=(i0);i<(int)(n);++i)
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vii;
typedef long long ll;


int main(){
    int a,b;cin>>a>>b;
    string ret = a+b==15?"+":"*";
    if(a+b!=15&&a*b!=15)ret="x";
    cout<<ret<<endl;
	return 0;
}

