#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<min(a,b)<<" ";
    cout<<max(0,a-(n-b))<<endl;
    return 0;
}