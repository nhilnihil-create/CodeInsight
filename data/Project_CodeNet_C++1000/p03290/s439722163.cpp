#include <bits/stdc++.h>
using namespace std;

int d,g;
pair<int,int> pc[11];
int ans=INT_MAX;

void bitSearch(){
    for(int bit=0;bit<(1<<d);bit++){
        int sum=0,cnt=0,max=-1;
        for(int i=0;i<d;i++){
            if(bit&(1<<i)){
                sum+=100*(i+1)*pc[i].first+pc[i].second;
                cnt+=pc[i].first;
            }else 
                max=i;
        }
        if(sum<g){
            int sum1=100*(max+1);
            int need=(g-sum+sum1-1)/sum1;
            if(need>=pc[max].first)
                continue;
            cnt+=need;
        }
        ans=min(ans,cnt);
    }
}

void solve(){
    bitSearch();
    cout << ans << endl;
}

int main(void) {
    cin >> d >> g;
    for(int i=0;i<d;i++)
        cin >> pc[i].first >> pc[i].second;

    solve();
    return 0;
}