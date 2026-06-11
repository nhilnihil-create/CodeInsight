/*alurquiza*/
//
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 18,SIZE2 = 1 << SIZE;
int DP[SIZE2];
int MAX[SIZE2][4];
vector<int> V(SIZE2);

bool comp(const int &a,const int &b){
    if(a == -1)
        return false;
    if(b == -1)
        return true;

    if(V[a] >= V[b])
        return true;
    return false;
}

void join(int mask,int smask){
    MAX[mask][2] = MAX[smask][0];
    MAX[mask][3] = MAX[smask][1];

    int N = 4;
    stable_sort(MAX[mask],MAX[mask] + N);
    N = unique(MAX[mask],MAX[mask] + N) - MAX[mask];

    stable_sort(MAX[mask],MAX[mask] + N,comp);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

//    freopen(".in","r",stdin);
//    freopen("F.out","w",stdout);

    int N;
    cin >> N;

    for(int i = 0;i < (1 << N);i++)
        cin >> V[i];

    for(int mask = 0;mask < (1 << N);mask++){
        MAX[mask][0] = mask;
        MAX[mask][1] = -1;

        for(int i = 0;(1 << i) <= mask;i++){
            if((1 << i) & mask){
                int nmask = mask ^ (1 << i);
                join(mask,nmask);
            }
        }
        if(MAX[mask][1] != -1)
            DP[mask] = V[MAX[mask][1]];
        DP[mask] += V[MAX[mask][0]];
    }

    for(int i = 1;i < (1 << N);i++){
        DP[i] = max(DP[i],DP[i - 1]);
        cout << DP[i] << '\n';
    }

    return 0;
}
