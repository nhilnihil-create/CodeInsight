#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){

    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a.at(i);
    int count = 0;

    for(int i = 0;i<n;++i){
        int x = a.at(i);
        while(x%2==0){
            count++;
            x/=2;
        }
    }
    cout<<count<<endl;


}
