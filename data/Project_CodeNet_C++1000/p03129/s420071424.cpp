#include<bits/stdc++.h>
typedef long long ll;
#define INF 100000000
#define MOD 100000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
    
        if((n+1)/2>=k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    return 0;
}