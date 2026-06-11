#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M;
    cin>>N>>M;
    vector<pair<long long,long long>>a(N);
    for(int i=0;i<N;i++){
        long long x,y;
        cin >>x>>y;
        a.at(i)=make_pair(x,y);
    }
    sort(a.begin(),a.end());
    long long summ=0;
    for(int i=0;i<N;i++){
         if(M-a.at(i).second>=0){
             M-=a.at(i).second;
             summ+=a.at(i).first*a.at(i).second;
         }
         else{
             summ+=M*a.at(i).first;
             break;
         }
    }
    cout<<summ<<endl;

}