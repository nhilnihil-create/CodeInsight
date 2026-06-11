#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,ll>P;

int main()
{
    int H,W,h,w;
    cin>>H>>W;
    cin>>h>>w;
    cout<<(H-h)*(W-w)<<endl;
}