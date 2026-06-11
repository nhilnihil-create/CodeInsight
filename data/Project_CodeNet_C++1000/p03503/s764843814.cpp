#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int open[110][15],sale[110][15];

    for(int i=0; i<N; i++){
        for(int j=0; j<10; j++){
            cin>>open[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<11; j++){
            cin>>sale[i][j];
        }
    }

    long long ans = -(1<<30);

    for(int m=1; m< (1<<10); m++){
        long long sum = 0;

        for(int i=0; i<N; i++){
            int cur = 0;
            for(int j=0; j<10; j++){
                if(m & (1 << j)) if(open[i][j]) cur++;
            }
            sum += sale[i][cur];
        }
        ans = max(ans,sum);
    }

    cout<<ans<<endl;

    return 0;
}