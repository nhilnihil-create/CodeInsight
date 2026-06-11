#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;

int main(){
    int n;cin>>n;
    vector<ii> r(n),b(n);
    vector<bool> used(n,false);
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        r[i]=make_pair(x,y);
    }
    for(int i=0;i<n;i++){
        cin>>x>>y;
        b[i]=make_pair(x,y);
    }
    sort(r.begin(),r.end());
    sort(b.begin(),b.end());

    int cnt=0;
    for(int i=0;i<n;i++){
        int j=0,id=-1,m=-1;
        while(r[j].first<b[i].first){
            if(r[j].second<b[i].second&&m<r[j].second&&!used[j]){
                m=r[j].second;
                id=j;
            }
            j++;
        }
        if(id!=-1){
            used[id]=true;
        }
    }
  for(int i=0;i<n;i++){
    if(used[i]) cnt++;
  }
    cout<<cnt<<endl;
    return 0;
}
