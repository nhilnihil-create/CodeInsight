#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int main(void) {
    int x,y,N;

    cin>>N>>x>>y;

    cout<<min(x,y)<<" "<<max(0,x+y-N)<<endl;

    return 0;
}
