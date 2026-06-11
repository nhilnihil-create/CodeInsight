#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;
    cin>>n;
    
    for(int i=0; 7*i<=n; i++){
        if((n-7*i)%4==0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    
    return 0;
}
