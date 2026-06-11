#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 200000
#define INF 1e12

using namespace std;

ll n,k,q,ar[N],ans = INF;

int main()
{
    cin >> n >> k >> q;

    rep(i,0,n)
    {
        cin >> ar[i];
    }

    rep(i,0,n)
    {
        ll s = ar[i];
        multiset < ll > nums;
        multiset < ll > possible;

        rep(j,0,n)
        {
            if(ar[j] < s)
            {
                while(nums.size() >= k)
                {
                    possible.insert(*(nums.begin()));
                    nums.erase(nums.begin());
                }

                nums.clear();
            }
            else
                nums.insert(ar[j]);
        }

        while(nums.size() >= k)
        {
            possible.insert(*(nums.begin()));
            nums.erase(nums.begin());
        }

        nums.clear();

        ll mini = (possible.empty()) ? -1 : *(possible.begin());
        ll maxi = mini;

        rep(j,0,q)
        {
            if(possible.empty())
            {
                maxi = INF;
                break;
            }

            maxi = *(possible.begin());
            possible.erase(possible.begin());
        }

        ans=min(ans,maxi-mini);
    }

    cout << ans;

    return 0;
}

