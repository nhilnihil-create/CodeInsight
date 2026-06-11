#include <bits/stdc++.h>

using namespace std;

vector <int> x[2],y[2];
int sn[2][2][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int ans=0;
    for(int i=0;i<29;i++){
        x[0].clear();x[1].clear();y[0].clear();y[1].clear();
        for(int j=0;j<n;j++){
            x[(a[j]>>i)&(1)].push_back(a[j]&((1<<i)-1));
            y[(b[j]>>i)&(1)].push_back(b[j]&((1<<i)-1));
        }
        sort(x[0].begin(),x[0].end(),greater<int>());
        sort(x[1].begin(),x[1].end(),greater<int>());
        sort(y[0].begin(),y[0].end());
        sort(y[1].begin(),y[1].end());
        memset(sn,0,sizeof(sn));
        for(int l=0;l<2;l++){
            for(int r=0;r<2;r++){
                int k=0;
                for(int j=0;j<x[l].size();j++){
                    while(k<y[r].size() && (x[l][j]+y[r][k]<(1<<i))){
                        k++;
                    }
                    sn[l][r][0]+=k;
                    sn[l][r][1]+=y[r].size()-k;
                }
            }
        }
        int val=0;
        val+=sn[0][0][1];
        val+=sn[0][1][0];
        val+=sn[1][0][0];
        val+=sn[1][1][1];
        ans+=(1<<i)*(val&1);
    }
    cout << ans << endl;
    return 0;
}
