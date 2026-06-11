#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    float n;
    cin>>n;
    float t,a;
    cin>>t>>a;
    float arr[(int)n];
    for(int i=0;i<n;i++)cin>>arr[i];
    float ans=1e7,h;
    for(int i=0;i<n;i++){
        if(fabs(a-(t-arr[i]*0.006))<ans){
            ans=fabs(a-(t-arr[i]*0.006));
            h=i+1;
        }
    }
    cout<<h;
}