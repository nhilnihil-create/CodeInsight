#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<long,long> >p(n);
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(),p.end());
    
    long ans = 0;
    int i=0;
    while(m>0){
        if(p[i].second>0){
            ans += p[i].first;
            p[i].second--;
            m--;
        }else{
            i++;
        }
    }
    cout << ans << endl;

}