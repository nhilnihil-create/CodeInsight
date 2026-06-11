#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int ans[100010];
vector <int> v[100010];
int main(){
  int n;
  while(cin>>n){
    ll tmp=1;
    memset(ans, -1, sizeof ans);
    ans[1]=2;
    for(int i=3; tmp<100010; ++i){
        tmp+=i-1;
        ans[tmp]=i;
    }
    int cnt=1;
    if(ans[n]!=-1){
        cout<<"Yes"<<endl;
        printf("%d\n",ans[n]);
        for(int i=1; i<=ans[n]; ++i){
            for(int j=i+1; j<=ans[n]; ++j){
                v[i].push_back(cnt);
                v[j].push_back(cnt);
                ++cnt;
            }
        }
        for(int i=1; i<=ans[n] ;++i){
            cout<<v[i].size()<<" ";
            for(int j=0; j<v[i].size(); ++j){
                printf("%d ",v[i][j]);
            }
            printf("\n");
        }
    }
    else{
        cout<<"No"<<endl;
    }
  }
  return 0;
}


