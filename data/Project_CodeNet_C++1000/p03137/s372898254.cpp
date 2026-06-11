#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define REP(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
long long maxv = 1e9;

int main()
{
    typedef vector<int> vi;

    int N,M;
    cin>>N>>M;
    vi arr(M);
    if(N>M){
        cout<<0;
        return 0;
    }else{
        REP(i,0,M-1){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        vi diff(M-1);
        REP(i,0,M-1-1){
            diff[i]=arr[i+1]-arr[i];
        }
        sort(diff.begin(), diff.end());
        int ans=0;
        REP(i,0,M-N-1){
            ans+=diff[i];
        }
        cout<<ans;
    }
}