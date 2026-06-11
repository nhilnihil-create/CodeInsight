#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const int N = 1e5 + 5;

int n, m;
vector < int > v[N];
int main()
{
    cin>>n;
    for (m = 0; m * (m - 1) / 2 < n; m++){}
    if (m * (m - 1) / 2 > n){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<m<<endl;
    int T = 1;
    for (int i = 1; i < m; i++){
        for (int j = i + 1; j <= m; j++){
            v[i].pb (T);
            v[j].pb (T);
            T++;
        }
    }
    for (int i = 1; i <= m; i++){
        cout<<v[i].size()<<" ";
        for (int j = 0; j < v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
