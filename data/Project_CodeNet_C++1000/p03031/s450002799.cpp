#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int nax = 1e7+7;
const int MOD = 1e9+7;

void printarr(vector<int> &v){
    for(int x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int n, m; cin>>n>>m;

    vector<int> switch_counts(m);

    vector<vector<int> > switches(m);

    vector<int> p(m);

    for(int i=0; i<m; i++){
        cin>>switch_counts[i];
        for(int sw=0; sw<switch_counts[i]; sw++){
            int x; cin>>x;
            x--;
            switches[i].push_back(x);
        }
    }

    for(int i=0; i<m; i++){
        cin>>p[i];
    }

    int ans = 0;

    // n switches ... so 2^n states of switches
    for(int mask=0; mask < (1<<n); mask++){
        vector<int> curr_switches(n, 0);
        for(int i=0; i<n; i++){
            // if(mask>>i & 1)
            if(mask & (1<<i)){
                curr_switches[i] = 1;
            }
        }

        // cout<<"mask: "<<mask<<"  switches-> ";
        // printarr(curr_switches);

        int satis = 0;
        for(int bulb=0; bulb<m; bulb++){
            int cnt = 0;
            for(int sw=0; sw<switch_counts[bulb]; sw++){
                if(curr_switches[switches[bulb][sw]] > 0){
                    cnt++;
                }
            }
            if(cnt%2==p[bulb]){
                satis++;
            }
        }
        if(satis==m){
            // cout<<"mask: "<<mask<<endl;
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}