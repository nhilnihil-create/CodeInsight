/// إِنَّ مَعَ الْعُسْرِ يُسْرًا
/// لَا أَبْرَحُ حَتَّىٰ أَبْلُغَ

#include <bits/stdc++.h>
#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld  double

#define HabdModeActive ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define PI acos(-1)
#define MAX 5000005
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
const int N = 2e5 + 5;


int main() {
    HabdModeActive
    string s;
    cin>>s;
    int cnt1 =0 ,cnt2=0;
    for(int i=0 ;i<s.size() ; i++)
    {
        if(i%2==0 && s[i]=='0')
            cnt1++;
        else if(i%2==1 && s[i]=='1')
            cnt1++;

        if(i%2==0 && s[i]=='1')
            cnt2++;
        else if(i%2==1 && s[i]=='0')
            cnt2++;

    }
    cout<<min(cnt1,cnt2);

    return 0;
}
