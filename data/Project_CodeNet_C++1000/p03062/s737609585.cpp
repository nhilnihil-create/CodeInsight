#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

using namespace std;

int main(){
    int N;  cin >> N;
    int cnt = 0, m=2000000000;
    ll s = 0;
    rep(i,N){
        int a;  cin >> a;
        if(a < 0)    cnt++;
        m = min(m,abs(a));
        s += abs(a);
    }
    if(cnt%2==0)    cout << s;
    else    cout << s - 2*m;
}