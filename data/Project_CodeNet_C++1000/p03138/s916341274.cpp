/** 
 *  Author : Parth Prajapati aka (PARTH_4399, hungry_chef)
 *  Institute : Pandit Deendayal Petroleum University
 **/
#include<bits/stdc++.h>

using namespace std; 

#define start_cooking int main()
#define food_is_ready return 0;
#define main_ingredient_added ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void cook()
{
    // start with your recipe
    long long n, k, powof2 = 1099511627776, cnt, ans = 0;
    int i, j;
    cin>>n>>k;
    vector<long long> a(n), b(n);
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    for(i=0;i<41;++i)
    {
        // cnt is count of numbers in array with ith bit set
        cnt = 0;
        for(j=0;j<n;++j)
        {
            if(a[j] >= powof2)
            {
                ++cnt;
                a[j] -= powof2;
            }
        }
        // if there are more zeros, set a bit
        // but check whether it doesn't exceed given k
        if(cnt*2 < n && ans+powof2 <= k)
            ans += powof2;
        powof2 /= 2LL;
    }
    //cout<<ans<<" ";
    long long sum = 0;
    for(i=0;i<n;++i)    sum += (ans^b[i]);
    cout<<sum<<"\n";
}

start_cooking
{
    main_ingredient_added
    //int t;
    //cin>>t;
    //while(t--)
        cook();
    food_is_ready
}