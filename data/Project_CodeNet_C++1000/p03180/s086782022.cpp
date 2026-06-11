/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 17;

const int mod = 1e9+7;


int n;
int a[N][N];
// dp[mask] = max score when you distirbute rabbits in mask no matter where they are
long long dp[1 << N];
long long pre[1 << N];

void go(int idx , const vector < int > & not_chosen , int taken , int a_taken , long long before_adding){
    //cout << idx << " " << taken << " " << a_taken << endl;
    if(idx == (int)not_chosen.size()){
        dp[a_taken] = max(dp[a_taken] , before_adding + pre[taken]);
        return;
    }
    go(idx + 1 , not_chosen , taken , a_taken , before_adding);
    taken |= (1 << not_chosen[idx]);
    a_taken |= (1 << not_chosen[idx]);
    go(idx + 1 , not_chosen , taken , a_taken , before_adding);
}

int main(){
    scanf("%d" , &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d" , &a[i][j]);
        }
    }
    for(int msk = 0; msk < (1 << n); msk++){
        for(int i = 0; i < n; i++){
            if(!(msk & (1 << i)))
                continue;
            for(int j = i+1; j < n; j++){
                if(msk & (1 << j)){
                    pre[msk] += a[i][j];
                }
            }
        }
    }

    for(int msk = 0; msk < (1 << n); msk++){
        vector < int > not_chosen;
        for(int i = 0; i < n; i++){
            if(!(msk & (1 << i)))
                not_chosen.push_back(i);
        }
        go(0 , not_chosen , 0 , msk , dp[msk]);
    }
    printf("%lld\n" , dp[ (1 << n) - 1]);
}
