#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    double ans=0;
    for(int i=1;i<=a;i++){
        double temp=1.0/a;
        int now=i;
        while(now<b){
            now*=2;
            temp/=2;
        }
        ans+=temp;
    }
    cout<<setprecision(12);
    cout<<ans;
}