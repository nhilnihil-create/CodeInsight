#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> r(n),b(n);
    vector<bool> rok(n,false),bok(n,false);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        r[i]=make_pair(y,x);
    }
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        b[i]=make_pair(x,y);
    }
    sort(r.rbegin(),r.rend());
    sort(b.begin(),b.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int bx=b[i].first;
        int by=b[i].second;
        for(int j=0;j<n;j++){
            int rx=r[j].second;
            int ry=r[j].first;
            if(rx<bx&&ry<by&&!rok[j]&&!bok[i]){
                ans++;
                rok[j]=true;
                bok[i]=true;
                break;
            }
        }
    }
    cout<<ans<<endl;
}