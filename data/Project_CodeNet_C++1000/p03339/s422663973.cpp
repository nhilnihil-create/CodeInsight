#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int se[1000010], sw[1000010];


int main(){
    cin>>N>>S;

    //累積和se i番目までのEの個数(0 - N-1)
    if(S[0] == 'E'){
        se[0] = 1;
        sw[0] = 0;
    } else {
        se[0] = 0;
        sw[0] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        if(S[i] == 'E') se[i] = se[i-1] + 1;
        else se[i] = se[i-1];

        if(S[i] == 'W') sw[i] = sw[i-1] + 1;
        else sw[i] = sw[i-1];
    }

    int mi = 1000000000;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        cnt += sw[i-1];
        cnt += (se[N-1] - se[i]);

        mi = min(mi,cnt);
    }

    cout << mi << endl;
    
}
