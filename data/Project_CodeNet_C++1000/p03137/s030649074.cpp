#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin >> n >> m;
    if(m==1){
        cout << "0" << endl;
        return 0;
    }
    vector<int>x(m);
    vector<int>dist(m-1);
    for(int i=0;i<m;i++){
        cin >> x.at(i);
    }
    sort(x.begin(),x.end());
    for(int i=0;i<m-1;i++){
        dist[i]=x[i+1]-x[i];
    }
    sort(dist.begin(),dist.end());
    for(int i=0;i<n-1;i++){
        dist.pop_back();
    }
    int ans=0;
  int size=dist.size();
    for(int i=0;i<size;i++){
        ans+=dist[i];
    }
    cout << ans << endl;
}
