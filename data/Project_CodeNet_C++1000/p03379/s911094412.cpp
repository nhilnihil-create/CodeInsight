#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v.push_back(arr[i]);
    }
    sort(arr,arr+n);
    int mid1=arr[(n/2)-1],mid2=arr[n/2];
    for(int i=0;i<n;i++){
        int cur=v[i];
        if(cur<=mid1)
            cout<<mid2<<endl;
        else
            cout<<mid1<<endl;

    }
    return 0;
}
