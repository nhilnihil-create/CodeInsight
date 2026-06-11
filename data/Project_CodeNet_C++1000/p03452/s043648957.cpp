#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using duo = pair<int,int>;

int Size[100100];
duo Par[100100];
int N,M;

bool Connect(int L,int R,int D);

int main() {
    scanf("%d %d",&N,&M);
    
    int i;

    for(i = 1;i <= N;i++){
        Size[i] = 1;
        Par[i] = duo(i,0);
    }

    for(i = 1;i <= M;i++){
        int l,r,d;
        scanf("%d %d %d",&l,&r,&d);
        if(Connect(l,r,d) == false) {
            puts("No");
            return 0;
        }
    }
    
    puts("Yes");
    
    return 0;
}
bool Connect(int L,int R,int D) {
    int S1 = 0;
    int p1 = L;
    vector<int> L1;
    L1.push_back(L);

    while(p1 != Par[p1].first) {
        S1 += Par[p1].second;
        p1 = Par[p1].first;
        L1.push_back(p1);
    }

    int S = S1;
    for(auto l : L1) {
        Par[l].first = p1;
        int delta = Par[l].second;
        Par[l].second = S;

        S -= delta;
    }

    int S2 = 0;
    int p2 = R;
    vector<int> L2;
    L2.push_back(R);

    while(p2 != Par[p2].first) {
        S2 += Par[p2].second;
        p2 = Par[p2].first;
        L2.push_back(p2);
    }
    S = S2;
    for(auto l : L2) {
        Par[l].first = p2;
        int delta = Par[l].second;
        Par[l].second = S;

        S -= delta;
    }

    if(p1 == p2) {
        return D == S2 - S1;
    } else {
        if(Size[p1] > Size[p2]) {
            Par[p2].first = p1;
            Par[p2].second = D + S1 - S2;
            
            Size[p1] += Size[p2];
        } else {
            Par[p1].first = p2;
            Par[p1].second = S2 - D - S1;

            Size[p2] += Size[p1];
        }

        return true;
    }
}