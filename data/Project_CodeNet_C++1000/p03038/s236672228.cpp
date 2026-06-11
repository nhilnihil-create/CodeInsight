#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    long long ans=0;
    cin>>N>>M;
    vector<int> A(N);
    vector<int> B(N);
    map<int,int> mp;
    int visit=-1;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        A.at(i)=a;
    }
    sort(A.begin(),A.end());
    for(int i=0;i<M;i++){
        int B,C;
        cin>>B>>C;
        mp[C]=min(mp[C]+B,N);
    }
    int check=0,rock=0;
    for(auto i=mp.end();i!=mp.begin();--i){
        if(check==0){
            check++;
            continue;  
        }
        int x=i->first;
        int y=i->second;
        for(int j=visit+1;j<visit+1+y;j++){
            B.at(j)=x;
            if(j==N-1){
                rock=54;
                break;
            }
        }
        if(rock==54){
            for(int i=0;i<N;i++){
                ans+=max(B.at(i),A.at(i));
            }
            cout<<ans<<endl;
            return 0;
        }
        visit=max(visit,visit+y);
    }
    int X=mp.begin()->first;
    int Y=mp.begin()->second;
    for(int i=visit+1;i<visit+1+Y;i++){
        B.at(i)=X;
        if(i==N-1){
            break;
        }
    }
    for(int i=0;i<N;i++){
      ans+=max(B.at(i),A.at(i));
    }
    cout<<ans<<endl;
    return 0;
}