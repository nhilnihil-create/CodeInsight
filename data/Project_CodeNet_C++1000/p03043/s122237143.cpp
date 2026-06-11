#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n,k;
    cin >> n >> k;
    double p=1.0/n;
    //cout << p << endl;
    int c[n];
    for(int i=1;i<=n;i++){
        int q=0,j=i;
        while(j<k){
            j*=2;
            q++;
        }
        c[i-1]=q;
        
    }

    double sum=0;
    for(int i=0;i<n;i++){
        sum+=pow(0.5,c[i]);
    }

    cout << fixed << setprecision(10) << sum*p << endl;
}