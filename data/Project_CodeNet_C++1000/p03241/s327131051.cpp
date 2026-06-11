#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M;
    cin >> N >> M;
    int num = M/N;
    while(num>=0){
        if((M-N*num)%num==0){
            cout << num << endl;
            return 0;
        }
        num--;
    }
    cout << "ERROR" << endl;
    return 0;
}