#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(j, m) for (int j = 0; j <= (int)(m); j++)

void chmin(int &a, int b){
    if(a>b){
        a=b;
    }
}

int n, aa, bb, cc;
vector<int> l;


int dfs(int i, int a, int b, int c)
{if(i==n){
    if(a*b*c==0){return 100000000;}
    return abs(a-aa)+abs(b-bb)+abs(c-cc);
}
int res=dfs(i+1,a,b,c);
chmin(res,dfs(i+1,a+l[i],b,c)+(a?10:0));
chmin(res,dfs(i+1,a,b+l[i],c)+(b?10:0));
chmin(res,dfs(i+1,a,b,c+l[i])+(c?10:0));
return res;
}
int main()
{

    cin >> n >> aa >> bb >> cc;
    l.resize(n);  
    rep(i, n)
    {
        cin >> l[i];
    }

    cout << dfs(0,0,0,0) << endl;
}