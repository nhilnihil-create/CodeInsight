#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 5e5+5;
// check for forloop
// take input
// overflow
// intialize variable
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        vec.push_back(arr[i]);
    }
    sort(vec.begin(),vec.end());
    int p1=vec[n/2-1], p2=vec[n/2];
    for(int i=0;i<n;i++){
        if(arr[i]<=p1){
            cout<<p2<<endl;
        }
        else cout<<p1<<endl;
    }
}