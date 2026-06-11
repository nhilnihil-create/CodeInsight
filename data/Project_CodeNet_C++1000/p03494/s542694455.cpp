#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
#define f first
#define s second
#define ll long long
#define ld long double
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int M=1e5+5;

int main() {
    IO
    int n,cnt=0;
    cin>>n;
    int arr[n+5],mn=1e9,x=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0) cnt++;
        x=0;
        while(arr[i]%2==0){
            x++;
            arr[i]/=2;
        }
        mn=min(mn,x);
    }
    if(cnt!=n){
        return cout<<0,0;
    }
    cout<<mn;
    return 0;
}
