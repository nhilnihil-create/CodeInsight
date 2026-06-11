#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin >> n >> m;
    if(m==1||n>=m){
        cout << "0" << endl;
        return 0;
    }
    vector<int>x(m);
    vector<pair<int,int>>dist;
    for(int i=0;i<m;i++){
        cin >> x.at(i);
        x.at(i)+=100000;
    }
    sort(x.begin(),x.end());
    for(int i=1;i<m;i++){
        int dif=x.at(i)-x.at(i-1);
        dist.push_back(make_pair(dif,i));
    }
    sort(dist.begin(),dist.end());
    reverse(dist.begin(),dist.end());
    vector<int>koma(n);
    koma[0]=-1;
    for(int i=0;i<n-1;i++){
        koma[i+1]=dist[i].second-1;
    }
    sort(koma.begin(),koma.end());
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=x[koma[i]]-x[koma[i-1]+1];
    }
    ans+=x[m-1]-x[koma[n-1]+1];
    cout << ans << endl;
}
