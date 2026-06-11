#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    map<int,int> M;
    for(int i=0;i<n;i++){
        M[A[i]]++;
    }
    int m = M.size();
    int ans = 0;
    for(auto x:M){
        if(x.first != x.second){
            if(x.first < x.second){
                ans += (x.second - x.first);
            }else{
                ans += x.second;
            }
        }
    }
    cout << ans << endl;
    
}