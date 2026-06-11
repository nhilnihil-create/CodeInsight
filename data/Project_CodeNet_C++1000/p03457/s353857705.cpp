#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/Tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define SC               scanf
#define PF               printf
#define ull              unsigned long long
#define ld               long double
#define D                double
#define F                first
#define S                second
#define pb               push_back
#define pf               push_front
#define MP               make_pair
#define sort_a(a)        sort(a.begin(),a.end());
#define sort_d(a)        sort(a.rbegin(),a.rend());
#define READ(f)          freopen(f, "r", stdin)
#define WRITE(f)         freopen(f, "w", stdout)
#define rev(s)           reverse(s.begin(),s.end())
#define it(it,mp)        for(auto it=mp.begin() ; it!=mp.end() ; it++)
#define IOS              ios_base :: sync_with_stdio(false); cin.tie(NULL);
#define ll long long
typedef pair<int,int>                   PII;
#define ordered_set Tree<PII, null_type,less<PII>, rb_Tree_tag,Tree_order_statistics_node_update>
const int N = 1e5 + 5;
const int inf = 1e9 + 1;
const double eps = 1e-15;
const double EPS = 1e-9;
const double PI = acos(-1.0);
int main()
{
    // IOS
    //READ("0test.txt");
    //WRITE("");
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    int ntime = 0, nx = 0, ny = 0;
    for (int i = 0; i < n; i++)
    {
        int time = t[i] - ntime;
        int distance = abs(x[i] - nx) + abs(y[i] - ny);
        if(time < distance)
        {
            return cout<<"No\n", 0 ;
        }
        else
        {
            if((time - distance) % 2 != 0)
                return cout<<"No\n",0;
        }
        ntime = t[i];
        nx = x[i];
        ny = y[i];
    }
    cout <<"Yes\n";


}

