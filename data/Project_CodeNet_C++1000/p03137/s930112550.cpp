#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(m),dist(m-1);
    for(int i=0; i<m; i++){
        cin >> x.at(i);
    }

    sort(x.begin(),x.end());

    for(int i=0; i<m-1; i++){
        dist.at(i)=x.at(i+1)-x.at(i);
        //cout << dist.at(i) << endl;
    }

    sort(dist.begin(),dist.end());

    long int ans=0;
    int i=0;
    while(i+n<m){
        ans+=dist.at(i);
        i++;
        //cout << i << endl;
    }

    cout << ans << endl;
}