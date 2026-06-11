#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=1e5+5, mxN=(1<<20)+5;
int mod=1e9+7;

int main()
{
    FIO;
string s1,s2;
cin>>s1>>s2;
if(s1[0]==s2[2]&&s1[1]==s2[1]&&s1[2]==s2[0])
    cout<<"YES";
else
    cout<<"NO";
    return 0;

}
