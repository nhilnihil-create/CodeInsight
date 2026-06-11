#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

LL comb(LL val, LL cnt);

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i,N)cin>>S[i];

    vector<int> count(5,0);
    REP(i,N){
        if(S[i][0]=='M'){count[0]++;}
        if(S[i][0]=='A'){count[1]++;}
        if(S[i][0]=='R'){count[2]++;}
        if(S[i][0]=='C'){count[3]++;}
        if(S[i][0]=='H'){count[4]++;}
    }

    LL ans = 0;
    int count_kind= 0;
    REP(i,5){
        if(count[i]>0)count_kind++;
    }
    if(count_kind < 3){
        cout << ans << endl;
        return 0;
    }

    vector<LL> target_count(count_kind,0LL);
    int l=0;
    REP(i,5){
        if(count[i]>0){
            target_count[l]=count[i];
            l++;
        }
    }


    for(int i=0; i<count_kind; i++){
        for(int j=i+1; j<count_kind; j++){
            for(int k=j+1; k<count_kind; k++){
                ans += target_count[i]*target_count[j]*target_count[k];
            }
        }
    }

    cout << ans << endl;
    return 0;
}

LL comb(LL val, LL cnt){
    LL ans = 1;
    for(int j=1; j<=cnt; j++){
        ans *= val - (j-1);
        ans /= j;
    }
    return ans;
}