#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> r(n),b(n);
    vector<bool> ok(n,false);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        r[i]=make_pair(b,a);
    }
    for(int i=0;i<n;i++){
        int c,d;
        cin>>c>>d;
        b[i]=make_pair(c,d);
    }
    int ans=0;
    sort(b.begin(),b.end());
    sort(r.rbegin(),r.rend());
    for(int i=0;i<n;i++){
        int bx=b[i].first;
        int by=b[i].second;
        for(int j=0;j<n;j++){
            int rx=r[j].second;
            int ry=r[j].first;
            if(rx<bx&&ry<by&&!ok[j]){
                ans++;
                ok[j]=true;
                break;
            }
        }
    }
    cout<<ans<<endl;
}