
#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define point complex<double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 2e5 + 10, mod = 998244353;
int n;

ll a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   string s1,s2;
   cin>>s1>>s2;
   if(s1[0]==s2[2]&&s1[1]==s2[1]&&s1[2]==s2[0]){
    cout<<"YES";
   }else cout<<"NO";
    return 0;
}
