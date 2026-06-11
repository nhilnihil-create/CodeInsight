#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
int main(){
    int n,sum=0,tmp;
    cin >> n;
    vector<vector<int> > vec(n,vector<int>(3));
    rep(i,n){
        cin >> vec.at(i).at(0);
        if(!i){
            vec.at(i).at(1)=0;
            sum+=abs(vec.at(i).at(0));
        }
        else{
            vec.at(i).at(1)=vec.at(i-1).at(0);
            vec.at(i-1).at(2)=vec.at(i).at(0);
            sum+=abs(vec.at(i).at(0)-vec.at(i).at(1));
        }
    }
    vec.at(n-1).at(2)=0;
    sum+=abs(vec.at(n-1).at(0));
    rep(i,n){
        if(!i)tmp=sum-abs(vec.at(i).at(0))-abs(vec.at(i).at(2)-vec.at(i).at(0))+abs(vec.at(i).at(2));
        else tmp=sum-abs(vec.at(i).at(0)-vec.at(i).at(1))-abs(vec.at(i).at(2)-vec.at(i).at(0))+abs(vec.at(i).at(2)-vec.at(i).at(1));
        cout << tmp << endl;
    }
}