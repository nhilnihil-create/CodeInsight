#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;


int main(){
    int N;
    cin >> N;

    int a,b;
    vector<P> pr;
    for(int i=0;i<N;++i){
       cin >> a >> b;
       pr.push_back(P(b,a));
    }
    vector<P> pb;
    for(int i =0;i<N;++i){
        cin >>a >> b;
        pb.push_back(P(a,b));
    }
    sort(pr.begin(),pr.end());//yでソート
    sort(pb.begin(),pb.end());//xでソート
    int ans =0;

    for(int i=0;i<N;i++){
        for(int j=N-1;j >= 0;--j){
            if(pb.at(i).second > pr.at(j).first && pb.at(i).first > pr.at(j).second){
                ans++;
                pr.at(j)=P(2*N,2*N);
                break;
            }
        }

    }
    cout << ans <<endl;


}