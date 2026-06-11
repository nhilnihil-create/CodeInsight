#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){
    int n;
    int count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        ll buf;
        cin>>buf;
        while(buf%2==0){
            count++;
            buf/=2;
        }
    }
    cout<<count<<endl;
    return 0;
}
