#include<bits/stdc++.h>

using namespace std;
#define int long long
/*                      */    //#undef int
#define INF 1000000009ll
#define INFL 1000000000000000018ll
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define mk make_pair
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef priority_queue<pair<int, PA> , vector<pair<int, PA> >, greater<pair<int, PA> > >PQG;

int N;
vector<int> V[1000];

signed main()
{
    cin >> N;
    if(N == 1){
        printf("Yes\n2\n1 1\n1 1\n");
        return 0;
    }
    bool flag = true;
    int res;
    int ans;
    for(int i = 2; i * (i + 1) / 2 <= N; i++){
        if(i * (i + 1) / 2 == N){
            res = i;
            ans = i;
            flag = false;
        }
    }
    if(flag){
        printf("No\n");
        return 0;
    }
    else{
        printf("Yes\n");
    }
    int in1 = 0, in2 = 1;
    for(int i = 1; i <= N; i++){
        V[in1].pb(i);
        V[in2 + in1].pb(i);
        if(in2 % res == 0){
            res--;
            in1++;
            in2 = 1;
        }
        else in2++;
    }
    printf("%lld\n", ans + 1);
    for(int i = 0; i <= ans; i++){
        printf("%lld ", (int)V[i].size());
        for(int j = 0; j < (int)V[i].size(); j++){
            printf("%lld", V[i][j]);
            if(j < (int)V[i].size() - 1){
                printf(" ");
            }
        }
        printf("\n");
    }


    return 0;
}
/*



*/
