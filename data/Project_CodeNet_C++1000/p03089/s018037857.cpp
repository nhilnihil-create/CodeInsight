#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    vector<int> b(N+1);
    for(int i = 1; i < N+1; i++) cin >> b.at(i);
    vector<int> ans(N);

    bool check;
    for(int i = 0; i < N ; i++){
        check = false;
        for(int j = N-i; j >= 1; j--){
            if(b[j] == j){
                b.erase(b.begin() + j);
                ans.at(i) = j;
                check = true;
                break;
            }
        }
        if(check){
            continue;
        }
        else{
            printf("-1\n");
            return 0;
        }
    }

    for (int i = N-1; i >= 0; i--)
    {
        printf("%d\n", ans.at(i));
    }
    return 0;
}