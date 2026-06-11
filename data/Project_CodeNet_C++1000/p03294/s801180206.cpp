#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){

    int N;
    cin>>N;
    int a;
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>a;
        sum+=a-1;
    }
    cout<<sum<<endl;
    return 0;
}
