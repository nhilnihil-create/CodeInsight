#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,a[Maxn];
bool check(int lim){
    map<int,int>Map;
    for(int i=2;i<=n;i++){
        if(a[i]<=a[i-1]){
            while(Map.size()&&Map.rbegin()->first>a[i])
                Map.erase(prev(Map.end()));
            for(int j=a[i];;j--){
                if(!j)return false;
                if(Map[j]==lim-1)Map.erase(j);
                else{
                    Map[j]++;
                    break;
                }
            }
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool succ=true;
    for(int i=1;i<n;i++)
        if(a[i]>=a[i+1])
            succ=false;
    if(succ){
        cout<<"1\n";
        return 0;
    }
    int l=2,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l<<"\n";
    return 0;
}