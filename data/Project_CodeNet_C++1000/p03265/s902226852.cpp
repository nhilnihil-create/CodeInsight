#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int difx,dify;
    difx=x2-x1;dify=y2-y1;
    int x3=x2-dify;int y3=y2+difx;
    int x4=x3-difx;int y4=y3-dify;
    cout << x3 << " " << y3 <<" " << x4  << " "<< y4 << endl;
}