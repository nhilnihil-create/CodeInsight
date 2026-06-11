// http://kmjp.hatenablog.jp/entry/2018/03/20/0900

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;
int N;
int A[202020];
int B[202020];
int C[602020];


int main() {
    int i,x,y;
    string s;

    cin>>N;
    for (i = 0; i < N; i++) cin>>A[i];
    for (i = 0; i < N; i++) cin>>B[i];

    int ret=0;
    for (i = 0; i < 29; i++) {
        for (x = 0; x < N; x++) C[x]=B[x]&((1<<(i+1))-1);
        sort(C,C+N);
        for (x = 0; x < 2 * N; x++) C[N+x]=C[x]+(1<<(i+1));
        long long tot=0;
        for (x = 0; x < N; x++) {
            y=A[x]&((1<<(i+1))-1);
            tot += lower_bound(C,C+3*N,(4<<i)-y)-lower_bound(C,C+3*N,(3<<i)-y);
        }
        if(tot%2) ret+=1<<i;
    }

    cout<<ret<<endl;
    return 0;
}
