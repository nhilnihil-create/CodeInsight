#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int ruiseki[100005];
bool sosu_bool[100005];
bool sosu_judge(int n)
{
    bool res = true;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0)
        {
            res = false;
            break;
        }
    }
    return res;
}
int main()
{
    int q;cin >>q;
    vector<int> l(q);
    vector<int> r(q);
    rep(i,q)
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 2; i <=100005; i++)
    {
        sosu_bool[i] = sosu_judge(i);
    }
    int temp = 0;
    for (int i = 2; i <= 100005; i++)
    {
        if(i%2==0)
        {
            ruiseki[i] = temp;
            continue;
        }
        if(sosu_bool[i] && sosu_bool[(i+1)/2])
        {
            temp++;
            
        }
        ruiseki[i] = temp;
    }
 

    rep(i,q)
    {
        cout << ruiseki[r[i]]-ruiseki[l[i]-1] << endl;
    }
}