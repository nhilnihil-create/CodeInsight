#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int a,b,c;cin>>a>>b>>c;
    
    int cap = max(a, max(b,c));
    int sum = a+b+c;
    
    if((sum-cap)%2==0){
        cout << (3*cap-sum)/2 << endl;
    }else{
        cout << (3*cap+3-sum)/2 << endl;
    }
    
    return 0;
}