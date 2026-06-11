
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

int mat[150][150];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mat[i][j] = 1;

    if(n%2==0)
    {
        for(int i=1;i<=n/2;i++)
            mat[i][n-i+1] = 0 , mat[n-i+1][i] = 0;
    }
    else
    {
        for(int i=1;i<=n/2;i++)
            mat[i][n-i] = 0 , mat[n-i][i] = 0;

    }

    int cnt = 0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            cnt += mat[i][j];

    cout<<cnt<<endl;

    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(mat[i][j])
                cout<<j<<" "<<i<<endl;


    return 0;
}



