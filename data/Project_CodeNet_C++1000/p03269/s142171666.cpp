#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N,M = 0,res = 0;
vector <pair<int,int> > e[123];
bool C[1000123];

void addEd(int u,int v,int x){
    e[u].push_back(make_pair(v,x));
    ++M;
}
void find(int u,int s = 0){
    if(u >= N){
        if(C[s]) cout << "FAIL AT s = " << s << endl;
        else ++res;
        C[s] = 1;
        return ;
    }
    for(int i = 0; i < e[u].size();++i){
        find(e[u][i].first,s + e[u][i].second);
    }
}
int main(){

    int L;
    cin >> L;

    if(L == 2){
        cout << "2 2" << endl;
        cout << "1 2 0" << endl;
        cout << "1 2 1" << endl;

        return 0;
    }
    --L;
    int r = 0;
    while((1 << (r + 1)) <= L) ++r;
    N = r + 1;

    //for(int i = 19; i >= 0; --i) cout << ((L >> i) & 1);
    //cout << endl;

    //cout << "N = " << N << endl;

        for(int i = 1; i < N; ++i){
            addEd(i,i + 1,0);
            addEd(i,i + 1,1 << (i - 1));
        }

    for(int i = r - 1; i >= 0; --i)
        if((L >> i) & 1){
            //cout << "L("<<i<<") = " << 1 << endl;
            int L2 = L^(1 << i);
            int lo = L2 & ( ((1 << (r + 1)) - 1) - ((1 << (i + 1)) - 1) );
            addEd(i + 1,N,lo);
        }
    
    addEd(1,N,L);

    //find(1);
    //cout << "res = " << res << endl;

    cout << N << " " << M << endl;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < e[i].size(); ++j) cout << i << " " << e[i][j].first << " " << e[i][j].second << endl;
    }

    return 0;
}