#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 5e5+5;
int par[MAXN];
int sz[MAXN];
multiset<int> s1;
vector<multiset<int>> v1;
int subarrays[MAXN];
int arr[MAXN];
int ans=1e9;
pair<int,int> arr2[MAXN];

int findpar(int a){
    if(par[a]==a){
        return a;
    }
    return par[a] = findpar(par[a]);
}
void merge(int a,int b){
    a = findpar(a);
    b = findpar(b);
    if(a==b){
        return;
    }
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    par[b] = a;
    sz[a]+=sz[b];
}
int main() {
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr2[i].first = arr[i];
        arr2[i].second = i;
    }
    sort(arr2+1,arr2+n+1);
    for(int i=1;i<=n;i++){
        int curr=  arr2[i].first;
        v1.clear();
        s1.clear();
        for(int j=1;j<=n;j++){
            if(arr[j]<curr){
                if(s1.size()>=k){
                    v1.push_back(s1);
                }
                s1.clear();
            }else{
                s1.insert(arr[j]);
            }
        }
        if(s1.size()>=k){
            v1.push_back(s1);
        }
        if(s1.size()){
            s1.clear();
        }
        multiset<int> s2;
        
        for(auto x:v1){
            int cnt=0;
            for(auto y:x){
                cnt++;
                if(cnt > x.size()-k+1){
                    break;
                }
               
                s2.insert(y);
            }
        }
        int cnt = 0;
        for(int x:s2){
            cnt++;
            if(cnt==q){
                ans = min(ans,x-curr);
                
            }
        }
    }
    cout<<ans<<endl;
}