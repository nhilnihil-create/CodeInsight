    #include<bits/stdc++.h>
    #include<math.h>

    typedef long long int ll;
    #define pb         push_back
    #define mp         make_pair
    #define F          first
    #define S          second
    #define fl(i,a,b)  for(ll i=a;i<b;i++)
    #define pll        pair<ll,ll>
    #define pii        pair<int,int>
    #define all(v)     v.begin(),v.end()
    #define M 1000000007
    #define tr(v, it) for(auto it = v.begin(); it != v.end(); it++)
    using namespace std;

    int solve(vector<vector<int> >& arr, int i, int n, vector<vector<int> >& dp, int activity )
    {
        if(i>n)
            return 0;

         if(dp[i][activity]!=-1)
            return dp[i][activity];


        int result = INT_MIN;

        if(activity!=0)
        result= max(result, arr[i][0]+solve(arr, i+1,n, dp, 0));
        if(activity!=1)
        result= max(result, arr[i][1]+solve(arr, i+1,n, dp, 1));
        if(activity!=2)
        result= max(result, arr[i][2]+solve(arr, i+1,n, dp, 2));
       // cout<<result<<" " <<i
        return dp[i][activity]=result;
    }

    int main()
    {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

       int n;
       cin>>n;
       vector<vector<int> > arr(n+1, vector<int>(3,0));
       for(int i=1; i<=n; i++)
       {
           cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
       }
       vector<vector<int> > dp(n+1,vector<int>(3,-1));
       int result = max(solve(arr, 1,n, dp,0),solve(arr, 1,n, dp,1));
       result = max(result, solve(arr, 1,n, dp,2));
       cout<<result;
        return 0;

    }

