/*
    IN THE NAME OF GOD
*/
#include <bits/stdc++.h>

#define loop(n) for(int i=0; i<n; i++)
#define loopB(n) for (int j=0; j<n; j++)
#define TAJIKISTAN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define in freopen("input.txt", "r" , stdin);
#define out freopen("output.txt", "w", stdout);

#define ll long long
#define ff first
#define ss second

// #pragma GCC optimize("Ofast")
using namespace std;

int* insertX(int arr[], int x, int position) {
    int arraySize = sizeof(arr)/sizeof(arr[0]);
    for (int i=arraySize; i>position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position]=x;
    return arr;
}

double dp[3005][3005];
double heads[3005];

void solve() {
    int N;
    cin>>N;
    loop(N) cin>>heads[i];
    dp[0][0]=(1-heads[0]);
    dp[0][1]=heads[0];
    for (int i=1; i<N; i++) {
        for (int j=0; j<=i+1; j++) {
            if (j==0){
                dp[i][j]=dp[i-1][j]*(1-heads[i]);
                continue;
            } else if (j==i+1) {
                dp[i][j]=dp[i-1][j-1]*heads[i];
            } else {
                dp[i][j]=dp[i-1][j-1]*heads[i]+dp[i-1][j]*(1-heads[i]);
            }
        }
    }
    double sum=0;
    for (int j=N/2+1; j<=N; j++) {
        sum+=dp[N-1][j];
    }
    cout<<setprecision(9)<<sum;
}

int main()
{
    //in out
    //TAJIKISTAN
    int t=1;
    //cin>>t;
    while (t--) {
        solve();
        cout<<'\n';
    }
    return 0;
}
