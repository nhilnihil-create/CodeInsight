#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
int n;
vector<int>ve;

int dp[N];
int main()
{
    int f=0;
    for(int i=2;i<=55555;i++){
            f=0;
        for(int j=2;j*j<=55555;j++){
            if(i%j==0) f=1;
        }
        if(f==0 && i%10==1) ve.push_back(i);
    }
     int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<ve[i]<<" ";
    }
    cout<<endl;
    return 0;
}
