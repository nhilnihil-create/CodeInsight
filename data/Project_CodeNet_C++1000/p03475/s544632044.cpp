#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int L[n][3];
    int T[n];
    int cnt = 0;
    int C,S,F;

    rep(i,n-1){
        cin>>C>>S>>F;
        L[i][0]=C;
        L[i][1]=S;
        L[i][2]=F;
    }
    rep(i,n-1){
        for(int j=i; j<n-1; j++){
            if(j==i){
                cnt = L[i][0]+L[i][1];
            }
            else{
                if(cnt<L[j][1]){
                    cnt=L[j][1];
                }

                if(cnt%L[j][2]!=0){
                    cnt+=L[j][2]-cnt%L[j][2];
                }
                cnt+=L[j][0];
            }
        }

        cout << cnt << endl;
        cnt=0;
    }
    cout << 0 << endl;
    return 0 ;
}