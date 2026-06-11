#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;
    cin>>n;
    int minsum = 200, j, k, sum;
    for(int i=1; i<n; i++){
        j = i;
        k = n-i;
        sum = 0;
        while(j){
            sum += j%10;
            j /= 10;
        }
        while(k){
            sum += k%10;
            k /= 10;
        }
        minsum = min(minsum, sum);
    }
    
    cout << minsum << endl;
    return 0;
}