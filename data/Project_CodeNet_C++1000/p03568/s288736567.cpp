#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n){
        int x;
        cin >> x;
        a[i] = x%2;
    }
    int sum = 1;
    rep(i,n){
        if(a[i]==0)sum*=2;
    }
    int allsum = pow(3,n);
    cout << allsum-sum << endl;

    return 0;
}
