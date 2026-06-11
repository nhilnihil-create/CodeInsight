#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n; cin>>n;
    long long a[n],M=-INF,m=INF,Mid,mid;
    rep(i,n){
        cin>>a[i];
        if(a[i]>M) M=a[i],Mid=i;
        if(a[i]<m) m=a[i],mid=i;
    }
    int cnt=0; vector<pair<int,int>> v;
    if(M==m&&M==0) cnt=0;
    else if(m>0){
        for(int i=1;i<n;i++){
            while(a[i-1]>a[i]){
                a[i]+=M;
                v.push_back({Mid+1,i+1});
                cnt++;
                if(a[i]>M) M=a[i],Mid=i;
            }
        }
    }else if(M<0){
        for(int i=n-2;i>=0;i--){
            while(a[i]>a[i+1]){
                a[i]+=m;
                v.push_back({mid+1,i+1});
                cnt++;
                if(a[i]<m) m=a[i],mid=i;
            }
        }
    }else{
        if(M<abs(m)){
            for(int i=n-2;i>=0;i--){
                while(a[i]>a[i+1]){
                    a[i]+=m;
                    v.push_back({mid+1,i+1});
                    cnt++;
                    if(a[i]<m) m=a[i],mid=i;
                }
            }
        }else{
            for(int i=1;i<n;i++){
                while(a[i-1]>a[i]){
                    a[i]+=M;
                    v.push_back({Mid+1,i+1});
                    cnt++;
                    if(a[i]>M) M=a[i],Mid=i;
                }
            }
        }
    }
    cout<<cnt<<endl;
    for(auto i:v){
        printf("%d %d\n",i.first,i.second);
    }
	return 0;
}
