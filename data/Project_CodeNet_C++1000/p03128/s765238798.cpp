#include<bits/stdc++.h>

using namespace std;

int num[]={0,2,5,5,4,5,6,3,7,6};

int main()
{
    int k,n;

    cin>>k>>n;

    vector<int>arr;

    for(int i=0;i<n;i++){
            int a;
    cin>>a;
        arr.push_back(a);
    }


    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());

   vector<int> dp(k+1, -10);

    dp[0]=0;

        dp[0] = 0;
    for(int i = 1; i <= k; i++) {
        for(int j=0;j<n;j++){
            if(i >= num[arr[j]]) {
                dp[i] = max(dp[i], dp[ i - num[arr[j]] ] + 1);
            }
        }
    }



   // cout<<dp[k]<<endl;
    int nokori = k;
    for(int i=0;i<dp[k];i++) {
    for(int j=0;j<n;j++){
            if(nokori >= num[arr[j]] && dp[ nokori - num[arr[j]] ] == dp[nokori] - 1) {
                cout << arr[j];
                nokori -= num[arr[j]];
                break;
            }
        }
    }
}
