#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,k;
    cin>>a>>b>>k;

    vector<int> x;

    for(int i = 100 ; i >0 ;i--){
        if(a%i == 0 && b%i == 0){
            x.push_back(i);
        }
    }

    cout<<x[k-1]<<endl;

    return 0;
}