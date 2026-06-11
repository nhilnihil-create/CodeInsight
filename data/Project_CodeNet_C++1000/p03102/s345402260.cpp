#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    int n,m,c;
    cin>>n>>m>>c;
    int cnt=0;
    int arr[m];
    for(int i=0;i<m;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        int temp=0;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            temp+=arr[i]*x;
        }
        if(temp+c>0)cnt++;
    }
    cout<<cnt;
}

